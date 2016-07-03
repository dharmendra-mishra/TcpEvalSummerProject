/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2016 NITK Surathkal
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Authors: Dharmendra Kumar Mishra <dharmendra.nitk@gmail.com>
 *          Mohit P. Tahiliani <tahiliani@nitk.edu.in>
 */

// Implement an object to configure topology in tcp-eval.

#include "configure-topology.h"
#include "traffic-parameters.h"

#include "ns3/log.h"
#include "ns3/data-rate.h"

//#include "ns3/core-module.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("ConfigureTopology");

NS_OBJECT_ENSURE_REGISTERED (ConfigureTopology);

TypeId
ConfigureTopology::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::ConfigureTopology")
    .SetParent<Object> ()
    .SetGroupName ("TcpEvaluationSuite")
/*    .AddAttribute ("BottleneckBandwidth",
                   "Bottleneck link capacity in Mbps",
                   DoubleValue (10),
                   MakeDoubleAccessor (&ConfigureTopology::m_bottleneckBandwidth),
                   MakeDoubleChecker<double> (0))
    .AddAttribute ("BottleneckCount", "Number of bottleneck links",
                   UintegerValue (1),
                   MakeUintegerAccessor (&ConfigureTopology::m_nBottlenecks),
                   MakeUintegerChecker<uint32_t> ())
    .AddAttribute ("RTTP",
                   "Round trip propagation delay in seconds",
                   TimeValue (Seconds (0.08)),
                   MakeTimeAccessor (&ConfigureTopology::m_rttp),
                   MakeTimeChecker ())
    .AddAttribute ("RttDiff",
                   "Flow RTT difference in seconds",
                   TimeValue (Seconds (0)),
                   MakeTimeAccessor (&ConfigureTopology::m_rttDifference),
                   MakeTimeChecker ())*/
  ;
  return tid;
}

ConfigureTopology::ConfigureTopology (void)
{
  m_tmixEnabled = false;
  m_centralLinkBufferBdp = 1.0;
}

ConfigureTopology::~ConfigureTopology (void)
{
}

void
ConfigureTopology::SetTopologyParameters ()
{
  m_centralLinkDelay = MilliSeconds ((m_rttp.GetMilliSeconds () * 0.5 * 0.8) / m_nCentralLinks);         //ms
  m_delayDifference = MilliSeconds ((m_rttDifference.GetMilliSeconds () * 1.0) / 4.0);          //ms
  m_nonCentralLinkDelay = MilliSeconds ((m_rttp.GetMilliSeconds () * 0.5 * 0.2) / 2.0);          //ms
  m_nonCentralLinkBandwidth = DataRate (m_centralLinkBandwidth.GetBitRate () * 1.0 * 2);          //Mbps

  if (m_tmixEnabled == true)
    {
      m_centralLinkBuffer = (m_centralLinkBufferBdp * (m_centralLinkBandwidth.GetBitRate () / 1000000) * m_bufferLength.GetMilliSeconds ()) / (8.0 * 1.5);
      m_nonCentralLinkBuffer = m_centralLinkBuffer;
    }
  else
    {
      // calculations pending due to avg_rtt_
      //m_centralLinkBuffer =
      m_nonCentralLinkBuffer = m_centralLinkBuffer;
    }
}

void
ConfigureTopology::SetCentralLinkBandwidth (DataRate centralLinkBandwidth)
{
  m_centralLinkBandwidth = centralLinkBandwidth;
}

DataRate
ConfigureTopology::GetCentralLinkBandwidth (void) const
{
  return m_centralLinkBandwidth;
}

void
ConfigureTopology::SetCentralLinkCount (uint32_t nCentralLink)
{
  m_nCentralLinks = nCentralLink;
}

uint32_t
ConfigureTopology::GetCentralLinkCount (void) const
{
  return m_nCentralLinks;
}

void
ConfigureTopology::SetRttp (Time rttp)
{
  m_rttp = rttp;
}

Time
ConfigureTopology::GetRttp (void) const
{
  return m_rttp;
}

void
ConfigureTopology::SetRttDifference (Time rttDifference)
{
  m_rttDifference = rttDifference;
}

Time
ConfigureTopology::GetRttDifference (void) const
{
  return m_rttDifference;
}

void
ConfigureTopology::SetDelayDifference (Time delayDifference)
{
  m_delayDifference = delayDifference;
}

Time
ConfigureTopology::GetDelayDifference (void) const
{
  return m_delayDifference;
}

void
ConfigureTopology::SetCentralLinkDelay (Time centralLinkDelay)
{
  m_centralLinkDelay = centralLinkDelay;
}

Time
ConfigureTopology::GetCentralLinkDelay (void) const
{
  return m_centralLinkDelay;
}

void
ConfigureTopology::SetNonCentralLinkDelay (Time nonCentralLinkDelay)
{
  m_nonCentralLinkDelay = nonCentralLinkDelay;
}

Time
ConfigureTopology::GetNonCentralLinkDelay (void) const
{
  return m_nonCentralLinkDelay;
}

void
ConfigureTopology::SetNonCentralLinkBandwidth (DataRate nonCentralLinkBandwidth)
{
  m_nonCentralLinkBandwidth = nonCentralLinkBandwidth;
}

DataRate
ConfigureTopology::GetNonCentralLinkBandwidth (void) const
{
  return m_nonCentralLinkBandwidth;
}

void
ConfigureTopology::SetCentralLinkBuffer (uint32_t centralLinkBuffer)
{
  m_centralLinkBuffer = centralLinkBuffer;
}

uint32_t
ConfigureTopology::GetCentralLinkBuffer (void) const
{
  return m_centralLinkBuffer;
}

void
ConfigureTopology::SetNonCentralLinkBuffer (uint32_t nonCentralLinkBuffer)
{
  m_nonCentralLinkBuffer = nonCentralLinkBuffer;
}

uint32_t
ConfigureTopology::GetNonCentralLinkBuffer (void) const
{
  return m_nonCentralLinkBuffer;
}

void
ConfigureTopology::SetEdgeDelay (Time edgeDelay)
{
  m_edgeDelay = edgeDelay;
}

Time
ConfigureTopology::GetEdgeDelay (void) const
{
  return m_edgeDelay;
}

void
ConfigureTopology::SetEdgeBandwidth (DataRate edgeBandwidth)
{
  m_edgeBandwidth = edgeBandwidth;
}

DataRate
ConfigureTopology::GetEdgeBandwidth (void) const
{
  return m_edgeBandwidth;
}

void
ConfigureTopology::SetCoreDelay (Time coreDelay)
{
  m_coreDelay = coreDelay;
}

Time
ConfigureTopology::GetCoreDelay (void) const
{
  return m_coreDelay;
}

void
ConfigureTopology::SetTmixEnabled (bool tmixEnabled)
{
  m_tmixEnabled = tmixEnabled;
}

bool
ConfigureTopology::IsTmixEnabled (void) const
{
  return m_tmixEnabled;
}

void
ConfigureTopology::SetPrefillT (Time prefillT)
{
  m_prefillT = prefillT;
}

Time
ConfigureTopology::GetPrefillT (void) const
{
  return m_prefillT;
}

void
ConfigureTopology::SetPrefillSi (Time prefillSi)
{
  m_prefillSi = prefillSi;
}

Time
ConfigureTopology::GetPrefillSi (void) const
{
  return m_prefillSi;
}

void
ConfigureTopology::SetScale (double scale)
{
  m_scale = scale;
}

double
ConfigureTopology::GetScale (void) const
{
  return m_scale;
}

void
ConfigureTopology::SetSimulationStopTime (Time simulationStopTime)
{
  m_simulationStopTime = simulationStopTime;
}

Time
ConfigureTopology::GetSimulationStopTime (void) const
{
  return m_simulationStopTime;
}

void
ConfigureTopology::SetSimulationEndTime (Time simulationEndTime)
{
  m_simulationEndTime = simulationEndTime;
}

Time
ConfigureTopology::GetSimulationEndTime (void) const
{
  return m_simulationEndTime;
}

}

