#include "FollowingHMM.h"

Sample::Sample()
{
	
}

Sample::~Sample()
{

}

FollowingHMM::FollowingHMM()
{
	window = 2;
	variance = 0.1;
	transitionVariance = 0.4;
	currentIndex = 0;
	confidence = 0;
	maxDistance = 0;

	followingMode = Types::OneShot;
}

FollowingHMM::~FollowingHMM()
{

}

double FollowingHMM::normalDistribution(double mean, double value, double sigma)
{
	double difference = value-mean;
	double temp = difference/sigma;
	double result = exp(-0.5*temp*temp)/(sigma*sqrt(2*3.14159265));
	return result;
}

double FollowingHMM::getTransitionProbability(int from, int to)
{
	int index;

	int difference = to - from;
	int middleIndex = transitionProbabilities.size()/2;
	
	if (followingMode == Types::OneShot)
	{
		if (difference>=0)
			index = middleIndex+difference;
		else
			index = -1;
	}
	else if (followingMode == Types::PingPong)
	{
		index = middleIndex+difference;
	}
	
	if (index>=0 && index<transitionProbabilities.size())
		return transitionProbabilities[index];
	else
		return 0;
}

void FollowingHMM::clearSamples()
{
	samples.clear();
	stateProbabilities.clear();
}

void FollowingHMM::addSample(Sample aSample)
{
	samples.push_back(aSample);
	stateProbabilities.push_back(0);
}

void FollowingHMM::resetStates(int newIndex)
{
	for (int i=0; i<stateProbabilities.size(); i++)
	{
		stateProbabilities[i] = 0;
	}

	currentIndex = newIndex;

	for (int i=newIndex-window; i<=newIndex+window; i++)
	{
		saveStateProbability(i, getTransitionProbability(i, currentIndex));
	}

	//Normalize
	normalizeStateProbabilities();
}

int FollowingHMM::findBestIndex()
{
	double probSum = this->getSumOfStateProbabilitiesInWindow();
	if (!probSum)
	{
		resetStates(currentIndex);
	}

	int result = currentIndex;

	bool leftSideScanned=false;
	bool rightSideScanned=false;

	int leftIndex = currentIndex;
	int rightIndex = currentIndex;
	double maxProbability = stateProbabilities[currentIndex];

	while (!leftSideScanned || !rightSideScanned)
	{
		leftIndex--;
		if (leftIndex < 0)
			leftSideScanned = true;
		else if (stateProbabilities[leftIndex]>maxProbability)
		{
			result = leftIndex;
			maxProbability = stateProbabilities[leftIndex];
		}

		rightIndex++;
		if (rightIndex >= stateProbabilities.size())
			rightSideScanned = true;
		else if (stateProbabilities[rightIndex]>maxProbability)
		{
			result = rightIndex;
			maxProbability = stateProbabilities[rightIndex];
		}
	}

	return result;
}

double FollowingHMM::distance(Sample a, Sample b)
{
	double sum = 0;
	for (int i=0; i<a.values.size(); i++)
	{
		sum+=(a.values[i]-b.values[i])*(a.values[i]-b.values[i]);
	}
	return sqrt(sum);
}

double FollowingHMM::emission(int index, Sample lastSample)
{
	double result = 0;

	if (index>=0 && index<samples.size())
	{
		double d = distance(samples[index], lastSample);
		result = normalDistribution(0, d/maxDistance, variance);
	}

	return result;
}

double FollowingHMM::getStateProbability(int index)
{
	if (index>=0 && index<stateProbabilities.size())
		return stateProbabilities[index];
	else
		return 0;
}

void FollowingHMM::clearStates()
{
	for (int i=0; i<stateProbabilities.size(); i++)
	{
		stateProbabilities[i] = 0;
	}
}

void FollowingHMM::saveStateProbability(int index, double probability)
{
		if (index>=0 && index<stateProbabilities.size())
			stateProbabilities[index] = probability;
}

double FollowingHMM::sumOfStateProbabilities()
{
	double sum = 0;
	for (int i=0; i<stateProbabilities.size(); i++)
	{
		sum+=stateProbabilities[i];
	}
	return sum;
}

void FollowingHMM::normalizeStateProbabilities()
{
	double sum = sumOfStateProbabilities();

	if (sum) 
		for (int i=0; i<stateProbabilities.size(); i++)
		{
			stateProbabilities[i] = stateProbabilities[i]/sum;
		}
}

void FollowingHMM::initialise()
{
	transitionProbabilities.clear();

	for (int i = currentIndex-window; i<=currentIndex+window; i++)
	{
			double sigma = transitionVariance*window/3;
			double result = normalDistribution(i, currentIndex, sigma);
			transitionProbabilities.push_back(result);
	}

	double tpSum=0;

	for (int i=0; i<transitionProbabilities.size(); i++)
	{
		tpSum += transitionProbabilities[i];
	}

	for (int i=0; i<transitionProbabilities.size(); i++)
	{
		transitionProbabilities[i] = transitionProbabilities[i]/tpSum;
	}

	resetStates(currentIndex);

	maxDistance = getMaximumDistance();
}

double FollowingHMM::getMaximumDistance()
{
	double maxdistance = 0;

	for (int i=0; i<samples.size(); i++)
		for (int j=0; j<samples.size(); j++)
		{
			double d = distance(samples[i], samples[j]);
			
			if (d>maxdistance)
				maxdistance = d;
		}

	return maxdistance;
}

void FollowingHMM::setCurrentIndex(int index)
{
	if (index<0)
		index = 0;

	if (index>=samples.size())
		index = samples.size()-1;

	currentIndex=index;
}

int FollowingHMM::follow(Sample lastSample)
{
	int result = currentIndex;

	vector<double> stateProbabilitiesInWindow;
	confidence = 0;
	for (int i = currentIndex-window; i<=currentIndex+window; i++)
	{
		double sumofproducts = 0;
		for (int ii = i-window; ii<=i+window; ii++)
		{
			double transitionProbability = getTransitionProbability(ii, i);
			double stateProbability = getStateProbability(ii);
			sumofproducts +=  transitionProbability*stateProbability;
		}

		double O = emission(i, lastSample);
		double stateProbability = O * sumofproducts;
		stateProbabilitiesInWindow.push_back(stateProbability);
		confidence+=stateProbability;
	}

	clearStates();

	int iter = 0;
	for (int i = currentIndex-window; i<=currentIndex+window; i++)
	{
		saveStateProbability(i, stateProbabilitiesInWindow[iter]);
		iter++;
	}

	vector<double> sp;
	for (int i=0; i<stateProbabilitiesInWindow.size(); i++)
	{
		sp.push_back(stateProbabilitiesInWindow[i]);
	}

	normalizeStateProbabilities();
	result = findBestIndex();

	return result;
}

void FollowingHMM::setWindow(double value)
{
	window = (int)(value*samples.size()/4);
	if (window==0)
		window = 1;
}

double FollowingHMM::getSumOfStateProbabilitiesInWindow()
{
	double sum = 0;

	for (int i = currentIndex-window; i<=currentIndex+window; i++)
	{
		if (i>=0 && i<stateProbabilities.size())
			sum += stateProbabilities[i];
	}

	return sum;
}