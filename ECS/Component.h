//
// Created by Madoc on 26/03/2023.
//

#ifndef COMPONENT_H
#define COMPONENT_H


class Component
{
public:
    //called when component is updated on start=
    virtual void OnStart();
    //called when component is updated
    virtual void OnUpdate();
};


#endif //COMPONENT_H
