#pragma once
/**
* @file
* @author Dennis Jönsson <zelebsel@gmail.com>
* @author Matteus Magnusson <senth.wallace@gmail.com>
* @version 1.0
* Copyright (©) A-Team.
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details at
* http://www.gnu.org/copyleft/gpl.html
*/

#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "../Utilities/Macros.h"
#include "../Utilities/Vectors.h"
#include <strstream>
#include <string>

namespace logic {

class Actor {
public:
  enum ActorTypes {
    ActorType_Invalid,
    ActorType_Player,
    ActorType_Enemy,
    ActorType_Munition,
    ActorType_StaticEnvironment,
    ActorType_Spectator
  };

  struct PlayerMovingInfo {
    PlayerMovingInfo() : mMoving(false), mRotating(false), mRotatingDirection(0), mMovingDirection(0) {}
    bool mMoving;
    bool mRotating;
    int mRotatingDirection;
    int mMovingDirection;
  };

  struct ActorSyncInfo {
    utilities::Position mPosition;
    utilities::Direction mDirection;
    utilities::Direction mSubsetDirection;
    utilities::Vec3Float mScale;
  };

  Actor();
  virtual ~Actor();

  /**
  * initiates the keyhandler
  */
  static void init();
  /**
  * Pure Virtual update function
  * @param deltaTime the time between calls, used in calculating movement
  */
  virtual void update(float deltaTime) = 0;

  /**
  * function that returns position struct
  * @return the position of the unit
  */
  inline const utilities::Position& getPosition() const { return mPosition; }

  /**
  * function that returns direction struct
  * @return the direction of the unit
  */
  inline const utilities::Direction& getDirection() const { return mDirection; }

  /**
  * function that sets the actors position to the given value
  * @param x the x-value
  * @param y the y-value
  * @param z the z-value
  */
  void setPosition(float x, float y, float z);

  /**
  * function that sets the actors position to the given value
  * @param pos The position as an utilities position
  */
  void setPosition(utilities::Position pos);

  /**
  * function that sets the actors destPosition to the given value
  * @param destPos The position as an utilities position
  */
  void setDestPosition(utilities::Position destPos);

  /**
  * function that sets the actors direction to the given value
  * @param x the x-value
  * @param y the y-value
  * @param z the z-value
  */
  void setDirection(float x, float y, float z);

  /**
  * Set the direction of the actor
  * @param direction the new direction
  */
  inline void setDirection(const utilities::Direction& direction) {
    setDirection(direction.x, direction.y, direction.z);
  }

  /**
  * function that returns the type of actor
  */
  ActorTypes getActorType();

  /**
  * Returns the subtype of the actor.
  * @return Return the subtype.
  */
  inline virtual int getActorSubType() const { return -1; }
  /**
  * function that sets the moving status of an actor
  */
  void setMoving(bool move);

  protected:

    ActorTypes mActorType;

    utilities::Position mPosition;
    utilities::Position mPrePosition;
    utilities::Position mDestPos;

    utilities::Direction mDirection;
    utilities::Direction mPreDirection;
    utilities::Direction mSubsetDirection;

    utilities::Vec3Float mScale;

    bool mMoving;
    bool mRotating;
    bool mSubsetRotating;
    bool mDead;
    bool mScaleChange;
    bool mVisible;
    bool mSync;

    float mSpeed;

    int mRotateDirection;
    int mSubsetRotateDirection;
    int mMovingDirection;


};

}


#endif