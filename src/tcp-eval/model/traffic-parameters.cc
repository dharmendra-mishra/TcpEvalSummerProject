/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "traffic-parameters.h"

#include "ns3/log.h"
#include "ns3/core-module.h"
#include <iostream>

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("TrafficParameters");

NS_OBJECT_ENSURE_REGISTERED (TrafficParameters);

TypeId
TrafficParameters::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::TrafficParameters")
    .SetParent<Object> ()
    .SetGroupName ("TcpEvaluationSuite")
  ;
  return tid;
}

TrafficParameters::TrafficParameters (void)
{
}

TrafficParameters::~TrafficParameters (void)
{
}

void
TrafficParameters::SetNumOfTmixFlows (uint32_t nTmixFlow)
{
  m_nTmixFlow = nTmixFlow;
}

uint32_t
TrafficParameters::GetNumOfTmixFlows (void) const
{
  return m_nTmixFlow;
}

void
TrafficParameters::SetNumOfTmixNodes (uint32_t nTmixNode)
{
	m_nTmixNode = nTmixNode;
}

uint32_t
TrafficParameters::GetNumOfTmixNodes (void) const
{
  return m_nTmixNode;
}

void
TrafficParameters::SetTmixCvName (std::string tmixCvName)
{
	m_tmixCvName = tmixCvName;
}

std::string
TrafficParameters::GetTmixCvName (void) const
{
  return m_tmixCvName;
}

void
TrafficParameters::SetTmixStdCvName (std::string tmixStdCvName)
{
	m_tmixStdCvName = tmixStdCvName;
}

std::string
TrafficParameters::GetTmixStdCvName (void) const
{
  return m_tmixStdCvName;
}

void
TrafficParameters::SetTmixAgentType (std::string tmixAgentType)
{
	m_tmixAgentType = tmixAgentType;
}

std::string
TrafficParameters::GetTmixAgentType (void) const
{
  return m_tmixAgentType;
}

void
TrafficParameters::SetTmixPacketSize (uint32_t tmixPacketSize)
{
	m_tmixPacketSize = tmixPacketSize;
}

uint32_t
TrafficParameters::GetTmixPacketSize (void) const
{
  return m_tmixPacketSize;
}

void
TrafficParameters::SetAqmTarget (uint32_t tmixPacketSize)
{
	m_aqmTarget = tmixPacketSize;
}

uint32_t
TrafficParameters::GetAqmTarget (void) const
{
  return m_aqmTarget;
}

void
TrafficParameters::SetAqmUsed (bool useAqm)
{
  m_useAqm = useAqm;
}

bool
TrafficParameters::IsAqmUsed (void) const
{
  return m_useAqm;
}

}

