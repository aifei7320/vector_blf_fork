/*
 * Copyright (C) 2013 Tobias Lorenz.
 * Contact: tobias.lorenz@gmx.net
 *
 * This file is part of Tobias Lorenz's Toolkit.
 *
 * Commercial License Usage
 * Licensees holding valid commercial licenses may use this file in
 * accordance with the commercial license agreement provided with the
 * Software or, alternatively, in accordance with the terms contained in
 * a written agreement between you and Tobias Lorenz.
 *
 * GNU General Public License 3.0 Usage
 * Alternatively, this file may be used under the terms of the GNU
 * General Public License version 3.0 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.  Please review the following information to
 * ensure the GNU General Public License version 3.0 requirements will be
 * met: http://www.gnu.org/copyleft/gpl.html.
 */

#pragma once

#include "VectorTypes.h"
#include "ObjectHeader.h"

#include "vector_blf_export.h"

namespace Vector {
namespace BLF {

/**
 * @brief LIN_STATISTIC
 *
 * @deprecated
 *
 * This info event is sent by the LIN hardware and transports bus statistics.
 */
class VECTOR_BLF_EXPORT LinStatisticEvent : public ObjectHeader
{
public:
    LinStatisticEvent();

    virtual char * parse(char * buffer);
    virtual size_t calculateObjectSize();

    /**
     * @brief application channel
     *
     * Channel number where the frame sent/received.
     */
    WORD channel;

    /** reserved */
    BYTE reserved1[6];

    /**
     * @brief bus load
     *
     * Bus load in percents
     */
    double busLoad;

    /**
     * @brief bursts total
     *
     * Total number of bursts
     */
    ULONG burstsTotal;

    /**
     * @brief bursts overrun
     *
     * Number of overrun bursts
     */
    ULONG burstsOverrun;

    /**
     * @brief frames sent
     *
     * Number of transmitted frames
     */
    ULONG framesSent;

    /**
     * @brief frames received
     *
     * Number of received frames
     */
    ULONG framesReceived;

    /**
     * @brief frames unanswered
     *
     * Number of frames without response
     */
    ULONG framesUnanswered;

    /** reserved */
    BYTE reserved2[4];
};

}
}
