#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include "model.h"
#include "arx.h"
#include "statespace.h"
#include "transferfunction.h"

namespace ModelHandler{

    template <typename Type>
    TransferFunction<Type> ss2tf(const StateSpace<Type> &SS);
    template <typename Type>
    TransferFunction<Type> ss2tfSISO(const StateSpace<Type> &SS);

    template <typename Type>
    TransferFunction<Type> arx2tf(const ARX<Type> &Arx, double sampleTime = 0);
    template <typename Type>
    StateSpace<Type> arx2SS(const ARX<Type> &Arx);


    template <typename Type>
    StateSpace<Type> tf2ss(const TransferFunction<Type> &TF);
    template <typename Type>
    StateSpace<Type> tf2ssSISO(const TransferFunction<Type> &TF);
    template <typename Type>
    ARX<Type> tf2arxSISO(const TransferFunction<Type> &TF, const Type &step);
//    template <typename Type>
//    ARX<Type> tf2arx(const TransferFunction<Type> &TF, const Type &step);

    template<typename Type> //ok
    StateSpace<Type> c2d(const StateSpace<Type> &SS, Type SampleTime);
    template<typename Type>
    TransferFunction<Type> c2d(const TransferFunction<Type>& TF, Type sampleTime);

    template<typename Type> //ok
    StateSpace<Type> d2c(const StateSpace<Type> &discreteSS);
    template<typename Type> //ok
    TransferFunction<Type> d2c(const TransferFunction<Type> &discreteTF);

    template<typename Type> //ok
    StateSpace<Type> integrativeModel(const StateSpace<Type> &SS);
    template<typename Type> //ok
    StateSpace<Type> predictionModel(const ModelHandler::StateSpace<Type> &SS_SSI,
                                     const unsigned &minPredictionHorizon,
                                     const unsigned &maxPredictionHorizon,
                                     const unsigned &controlHorizon);
}

#ifdef testModel
    #include "../../../src/modelLibs/conversions.hpp"
#else
    #include "SistemasdeControle/src/modelLibs/conversions.hpp"
#endif

#endif // CONVERSIONS_H

