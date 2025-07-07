#include <omnetpp.h>
#include <python3.8/Python.h>

using namespace omnetpp;

class PythonPredictor : public cSimpleModule {
protected:
    virtual void initialize() override {
        Py_Initialize();
    }

    double predictDelay(int frameSize, int queueLength) {
        PyObject *pModule = PyImport_ImportModule("predict_delay");
        PyObject *pFunc = PyObject_GetAttrString(pModule, "predict");

        PyObject *pArgs = PyTuple_Pack(2,
            PyLong_FromLong(frameSize),
            PyLong_FromLong(queueLength));

        PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
        double result = PyFloat_AsDouble(pValue);

        Py_DECREF(pModule);
        Py_DECREF(pFunc);
        Py_DECREF(pArgs);
        Py_DECREF(pValue);

        return result;
    }

    virtual void finish() override {
        Py_Finalize();
    }
};

Define_Module(PythonPredictor);
