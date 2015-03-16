#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SignalTimeLine.h"

class Sample
{
public:
	Sample();
	~Sample();

	vector<double> values;
private:

};
 
class FollowingHMM
{
public:
	FollowingHMM();
	~FollowingHMM();

	int window;
	double variance;
	double transitionVariance;
	double confidence;
	int currentIndex;

	bool cycleJump;

	int followingMode;

	int follow(Sample lastSample);

	void clearSamples();
	void addSample(Sample aSample);
	void resetStates(int newIndex);
	void clearStates();

	void initialise();

	void setCurrentIndex(int index);

	vector<Sample> samples;

	void setWindow(double value);

private:
	vector<double> stateProbabilities;
	vector<double> transitionProbabilities;

	double maxDistance;

	double getTransitionProbability(int from, int to);
	
	int findBestIndex();

	double getSumOfStateProbabilitiesInWindow();

	double distance(Sample a, Sample b);
	double emission(int index, Sample lastSample);
	double getStateProbability(int index);
	void saveStateProbability(int index, double probability);
	void normalizeStateProbabilities();
	double sumOfStateProbabilities();

	double getMaximumDistance();

	double normalDistribution(double mean, double value, double sigma);
};