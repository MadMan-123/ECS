/*
 * ECS system
 * -by MadMan
 *
 *
 * This is a copy and paste template for Entity component systems in c++ following OOP designs
 * the code is comprised of Entities and Components, it is similar to GameObjects and Components in Unity
 *
 * Example of Code
 *
 *
 * class PlayerController : public Component
 * {
 *      float fSpeed;
 *      Vec2 Direction;
 *
 *      void OnUpdate() override
 *      {
 *           Vec2 Product = Direction * fSpeed;
 *
 *          //reference to parent entity
 *          parent.GetComponent<Rigidbody2D>().AddForce(Product);
 *      }
 *
 * };
 *
 * class Player : public Entity
 * {
 *      PlayerController controller;
 *
 *      void OnStart() override
 *      {
 *          //should pass a reference of the controller
 *
 *          controller = AddComponent<PlayerController>();
 *
 *      }
 * };
 *
 *
 * int main()
 * {
 *      Player player;
 *      //how the entities are stored
 *      EntityManager manager;
 *
 *      //will add the player and will run OnStart
 *      manager.Add(player);
 *
 *      //will run OnUpdate
 *      EntityManager.HandleUpdates();
 *
 *      //will remove player
 *      manager.Remove(&Player);
 * }
 *

 */


#include <iostream>
#include "ECS/Entity.h"
#include "ECS/Component.h"
#include "ECS/EntityManager.h"

class TestComponent : public Component
{
    int i = 0;
    void OnUpdate() override
    {
        i++;
        std::cout << i << " ";
    }
};

class TestComponent2 : public Component
{
    const char* Strings[11]
    {
                "Yer Maw",
                "Yer Da",
                "I LOVE CHINA CCP",
                "Why am i still here",
                "I want to go to sleep",
                "I cant fucking sleep",
                "Racialy motivated",
                "Suicide seems alr rn",
                "Gonna sql inject ur mum ",
                "I AM A SUSPECTED TERRORIST",
                "Shit n piss"
    };

    int iRand = 0;
    void OnStart() override
    {
        srand (time(NULL));

    }

    void OnUpdate() override
    {
        iRand = rand() % 10 ;

        std::cout << Strings[iRand] << std::endl;
    }
};


int main()
{
    EntityManager manager;
    Entity entity;
    entity.AddComponent<TestComponent>();
    entity.AddComponent<TestComponent2>();
    manager.RunStarts();

    manager.AddEntity(entity);

    for (int i = 0; i < 100; ++i)
    {
        manager.RunUpdates();
    }

    std::cout << "Running" << std::endl;
}
