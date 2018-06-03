/**
 * @file
 * @brief     This file contains a class that represents the data that is needed to predict positions of an object.
 * @author    Daniel van vliet
 * @license   See LICENSE
 */

#ifndef OBJECTDATA_HPP
#define OBJECTDATA_HPP
#include "vector3d.hpp"
#include <array>

class ObjectData {
  private:
    std::array<Vector3D, 10> positions;
    std::array<int, 10> measurementDelay;
    Vector3D speed;

  public:
    ObjectData();

    /**
     * @brief This method adds a new sample
     *
     *  This method adds a new sample to the internal stored sample array
     *  This function shifts the new sample into the position and measurementDelay arrays.
     *  The position and delay are inserted at the end of the arrays. This is using the First in first out principle.
     *  This method is assuming the sample size of the arrays is 10
     *
     * @param[in] newPosition : a new sample as vector3D
     * @param[in] delayMs : the delay between last sample in milliseconds.
     */
    void addSample(Vector3D newPosition, uint32_t delayMs);

    /**
     * @brief a getter for position.
     *
     * This method returns the position for the given index.
     * If the index is out of bounds a Vector3D with coords (0, 0, 0) is returned.
     *
     * @param[in] objectId : the position index as integer
     *
     * @return A Vector3D as position of the object.
     */
    Vector3D getPosition(const uint32_t &index);

    /**
     * @brief a setter for speed.
     *
     * This method sets the speed to a new value.
     *
     * @param[in] newSpeed : the new speed as Vector3D
     */
    void setSpeed(const Vector3D &newSpeed);

    /**
     * @brief a getter for speed.
     *
     * This method returns the speed.
     * @return A Vector3D as speed of the object.
     */
    Vector3D getSpeed();

    /**
     * @brief clears internal samples.
     *
     * This function clears the stored samples, setting all integers to 0
     * and Vector3Ds to Vector3D(0,0,0).
     */
    void clearSamples();
};

#endif