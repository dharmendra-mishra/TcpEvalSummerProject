/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef TRAFFIC_PARAMETERS_H
#define TRAFFIC_PARAMETERS_H

#include <stdint.h>
#include "ns3/core-module.h"

namespace ns3 {

/**
 * \brief Initializes the traffic parameters.
 *
 * This class consists of setters and getters for traffic parameters
 * The object of this class is passed to the methods where traffic
 * parameters are used
 */
class TrafficParameters : public Object
{
public:
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);

  /**
   * \brief Constructor
   */
  TrafficParameters (void);

  /**
   * \brief Destructor
   */
  ~TrafficParameters (void);

  void SetNumOfTmixFlows (uint32_t nTmixFlow);

  uint32_t GetNumOfTmixFlows (void) const;

  void SetNumOfTmixNodes (uint32_t nTmixNode);

  uint32_t GetNumOfTmixNodes (void) const;

  void SetTmixCvName (std::string tmixCvName);

  std::string GetTmixCvName (void) const;

  void SetTmixStdCvName (std::string tmixStdCvName);

  std::string GetTmixStdCvName (void) const;

  void SetTmixAgentType (std::string tmixAgentType);

  std::string GetTmixAgentType (void) const;

  void SetTmixPacketSize (uint32_t tmixPacketSize);

  uint32_t GetTmixPacketSize (void) const;

  void SetAqmTarget (uint32_t tmixPacketSize);

  uint32_t GetAqmTarget (void) const;

  /**
   * \brief Set whether AQM is to be used
   *
   * \param useAqm True if AQM is enabled
   */
  void SetAqmUsed (bool useAqm);

  /**
    * \brief Check whether AQM is to be used
    *
    * \return True if AQM is enabled
    */
  bool IsAqmUsed (void) const;


private:
  uint32_t     m_nTmixFlow;
  uint32_t     m_nTmixNode;
  std::string  m_tmixCvName;       //may be list  dkm
  std::string  m_tmixStdCvName;    //may be list  dkm
  std::string  m_tmixAgentType;
  uint32_t     m_tmixPacketSize;
  uint32_t     m_tmixDebugOutput;   //dkm required or not? and maybe list

  std::string  m_testTcp;			//dkm required or not?
  std::string  m_standardTcp;		//dkm required or not?

  bool         m_useAqm;                 //!< Enable or disable AQM in routers
  uint32_t     m_aqmTarget;			//dkm
};

}

#endif /* TRAFFIC_PARAMETERS_H */

