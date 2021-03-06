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
 * @brief CAN_MESSAGE
 *
 * @deprecated
 *
 * CAN data or CAN remote frame received or transmitted on a CAN channel.
 */
class VECTOR_BLF_EXPORT CanMessage : public ObjectHeader
{
public:
    CanMessage();

    virtual char * parse(char * buffer);
    virtual size_t calculateObjectSize();

    /**
     * @brief application channel
     *
     * Channel the frame was sent or received.
     */
    WORD channel;

    /**
     * @brief CAN dir & rtr
     *
     * CAN Message Flags
     *
     * CAN dir, rtr, wu & nerr encoded into flags:
     * - Bit 0: TX
     * - Bit 5: NERR
     * - Bit 6: WU
     * - Bit 7: RTR
     */
    BYTE flags;

    /**
     * @brief CAN dlc
     *
     * Data length code of frame (number of valid data
     * bytes, max. 8)
     */
    BYTE dlc;

    /**
     * @brief CAN ID
     *
     * Frame identifier.
     */
    DWORD id;

    /**
     * @brief CAN data
     *
     * CAN data bytes
     */
    BYTE data[8];
};

}
}
