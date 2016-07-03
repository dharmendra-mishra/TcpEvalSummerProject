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

// Define an object to configure topology in tcp-eval.

#ifndef CONFIGURE_TOPOLOGY_H
#define CONFIGURE_TOPOLOGY_H

#include <stdint.h>

#include "ns3/object.h"
#include "ns3/core-module.h"
#include "ns3/data-rate.h"

namespace ns3 {

/**
 * \brief base class to configure the topology
 *
 * It initializes parameters used in the configuration of the topology.
 * Other classes like Dumbbell and ParkingLot should extend this class.
 */
class ConfigureTopology : public Object
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
  ConfigureTopology (void);

  /**
   * \brief Destructor
   */
  ~ConfigureTopology (void);

  /**
   * \brief Initializes the topology parameters
   *
   * \param traffic Object of TrafficParameters class that contains traffic information
   * \param nBottlenecks Number of Bottleneck links. For dumbbell it is 1 and for other topologies >= 1
   */
  void SetTopologyParameters ();

  void SetCentralLinkBandwidth (DataRate centralLinkBandwidth);

  DataRate GetCentralLinkBandwidth (void) const;

  void SetCentralLinkCount (uint32_t nCentralLink);

  uint32_t GetCentralLinkCount (void) const;

  void SetRttp (Time rttp);

  Time GetRttp (void) const;

  void SetRttDifference (Time rttDifference);

  Time GetRttDifference (void) const;

  void SetDelayDifference (Time delayDifference);

  Time GetDelayDifference (void) const;

  void SetCentralLinkDelay (Time centralLinkDelay);

  Time GetCentralLinkDelay (void) const;

  void SetNonCentralLinkDelay (Time nonCentralLinkDelay);

  Time GetNonCentralLinkDelay (void) const;

  void SetNonCentralLinkBandwidth (DataRate nonCentralLinkBandwidth);

  DataRate GetNonCentralLinkBandwidth (void) const;

  void SetCentralLinkBuffer (uint32_t centralLinkBuffer);

  uint32_t GetCentralLinkBuffer (void) const;

  void SetNonCentralLinkBuffer (uint32_t nonCentralLinkBuffer);

  uint32_t GetNonCentralLinkBuffer (void) const;

  void SetEdgeDelay (Time edgeDelay);

  Time GetEdgeDelay (void) const;

  void SetEdgeBandwidth (DataRate edgeBandwidth);

  DataRate GetEdgeBandwidth (void) const;

  void SetCoreDelay (Time CoreDelay);

  Time GetCoreDelay (void) const;

  void SetTmixEnabled (bool tmixEnabled);

  bool IsTmixEnabled (void) const;

  void SetPrefillT (Time prefillT);

  Time GetPrefillT (void) const;

  void SetPrefillSi (Time prefillSi);

  Time GetPrefillSi (void) const;

  void SetScale (double scale);

  double GetScale (void) const;

  /**
    * \brief Set the simulation time in seconds
    *
    * \param simulationTime Time when the simulation should stop
    */
  void SetSimulationStopTime (Time simulationStopTime);

  /**
    * \brief Get the simulation time in seconds
    *
    * \return the simulation time in seconds
    */
  Time GetSimulationStopTime (void) const;

  void SetSimulationEndTime (Time simulationEndTime);

  Time GetSimulationEndTime (void) const;

protected:
  DataRate m_centralLinkBandwidth;      //!< Bandwidth of central link in Mbps
  uint32_t m_nCentralLinks;             //!< Number of central links.
  Time     m_rttp;                      //!< Round trip propagation delay in seconds
  Time     m_rttDifference;             //!< Flow RTT difference in seconds
  Time     m_delayDifference;           //!< Delay difference in seconds
  Time     m_centralLinkDelay;           //!< Delay of bottleneck link in seconds
  DataRate m_nonCentralLinkBandwidth;    //!< Bandwidth of non-bottleneck link in Mbps
  Time     m_nonCentralLinkDelay;        //!< Delay of non-bottleneck link in seconds
  double  m_nonCentralLinkBuffer;       //!< Size of the non-bottleneck buffer
  double   m_centralLinkBufferBdp;       //!< Bandwidth-Delay Product for the bottleneck link
  double   m_centralLinkBuffer;          //!< Size of the bottleneck buffer
  Time     m_edgeDelay;
  DataRate m_edgeBandwidth;
  Time     m_coreDelay;
  bool    m_tmixEnabled;
  Time     m_prefillT;
  Time     m_prefillSi;
  double  m_scale;
  Time     m_simulationStopTime;
  Time     m_simulationEndTime;
  Time     m_bufferLength;
};
}

#endif /* CONFIGURE_TOPOLOGY_H */

