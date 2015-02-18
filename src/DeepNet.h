#include <iostream>
#include <boost/program_options.hpp>
#include "config.h"
#include "LogicalCube.h"
#include "Connector.h"
#include "Kernel.h"
#include "bridges/AbstractBridge.h"
#include "bridges/MaxPoolingBridge.h"
#include "bridges/ReLUBridge.h"
#include "bridges/ConvolutionBridge.h"
#include "bridges/FullyConnectedBridge.h"
#include "bridges/SoftmaxLossBridge.h"
#include "bridges/DropoutBridge.h"
#include "bridges/LRNBridge.h"
#include "bridges/ParallelizedBridge.h"
#include "bridges/FunnelBridge.h"
#include "Layer.h"
#include "parser/corpus.h"
#include "util.h"
#include <algorithm>

typedef LogicalCube<DataType_SFFloat, Layout_CRDB> LogicalCubeFloat;
typedef std::vector<AbstractBridge<DataType_SFFloat, Layout_CRDB, DataType_SFFloat, Layout_CRDB> *> BridgeVector;

void load_and_train_network(const char * file, const std::string data_binary, const std::string model_file);

float load_and_test_network(const char * file, const std::string data_binary, const std::string model_file);

Corpus * load_network(const char * file, const string & data_binary, cnn::SolverParameter & solver_param,
    cnn::NetParameter & net_param, BridgeVector & bridges, bool train);

Corpus * read_corpus_from_lmdb(const cnn::NetParameter & net_param, const std::string data_binary, bool train);

void construct_network(BridgeVector & bridges, Corpus & corpus, const cnn::NetParameter & net_param,
  const cnn::SolverParameter & solver_param);

int find_accuracy(const LogicalCubeFloat * const labels, const LogicalCubeFloat * output);