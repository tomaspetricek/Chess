//
// Created by Tomáš Petříček on 30.07.2021.
//

#ifndef CHESS_CALLBACK_H
#define CHESS_CALLBACK_H

#include <functional>

template<class ClassType, typename ReturnType>
class Callback {
    ClassType *obj;
    std::function<void(ClassType *)> method;

public:
    Callback(ClassType *obj, std::function<ReturnType(ClassType *)> method);

    ReturnType operator()();
};

template<class ClassType, typename ReturnType>
Callback<ClassType, ReturnType>::Callback(ClassType *obj, std::function<ReturnType(ClassType *)> method)
        : obj{obj}, method{std::move(method)} {}

template<class ClassType, typename ReturnType>
ReturnType Callback<ClassType, ReturnType>::operator()() {
    return method(obj);
}


#endif //CHESS_CALLBACK_H
