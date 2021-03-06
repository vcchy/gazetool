#pragma once

#include <vector>
#include <utility>
#include <dlib/svm.h>
#include <opencv2/opencv.hpp>

#include "gazehyps.h"
#include "abstractlearner.h"

class VerticalGazeLearner : public AbstractLearner
{
public:
    VerticalGazeLearner(TrainingParameters &params);
    virtual ~VerticalGazeLearner();
    virtual void loadClassifier(const std::string& filename);
    //virtual void extractFeatures(GazeHyp &ghyp);
    virtual void classify(GazeHyp &ghyp);
    virtual void train(const std::string &outfilename);
    virtual void visualize(GazeHyp& ghyp, double mutualGazeTolerance);
    virtual std::string getId();

protected:
    typedef dlib::linear_kernel<sample_type> kernel_type;
    typedef dlib::decision_function<kernel_type> dec_funct_type;
    dec_funct_type learned_function;
    boost::optional<dlib::matrix<double,0,1> > getFeatureVector(GazeHyp &ghyp);
};
