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

#include "WlanStatistic.h"

#include <cstring>

namespace Vector {
namespace BLF {

WlanStatistic::WlanStatistic() :
    ObjectHeader(),
    channel(),
    flags(),
    rxPacketCount(),
    rxByteCount(),
    txPacketCount(),
    txByteCount(),
    collisionCount(),
    errorCount()
{
}

char * WlanStatistic::parse(char * buffer)
{
    size_t size;

    // previous data
    buffer = ObjectHeader::parse(buffer);

    // channel
    size = sizeof(channel);
    memcpy((void *) &channel, buffer, size);
    buffer += size;

    // flags
    size = sizeof(flags);
    memcpy((void *) &flags, buffer, size);
    buffer += size;

    // rxPacketCount
    size = sizeof(rxPacketCount);
    memcpy((void *) &rxPacketCount, buffer, size);
    buffer += size;

    // rxByteCount
    size = sizeof(rxByteCount);
    memcpy((void *) &rxByteCount, buffer, size);
    buffer += size;

    // txPacketCount
    size = sizeof(txPacketCount);
    memcpy((void *) &txPacketCount, buffer, size);
    buffer += size;

    // txByteCount
    size = sizeof(txByteCount);
    memcpy((void *) &txByteCount, buffer, size);
    buffer += size;

    // collisionCount
    size = sizeof(collisionCount);
    memcpy((void *) &collisionCount, buffer, size);
    buffer += size;

    // errorCount
    size = sizeof(errorCount);
    memcpy((void *) &errorCount, buffer, size);
    buffer += size;

    return buffer;
}

size_t WlanStatistic::calculateObjectSize()
{
    size_t size =
            ObjectHeader::calculateObjectSize() +
            sizeof(channel) +
            sizeof(flags) +
            sizeof(rxPacketCount) +
            sizeof(rxByteCount) +
            sizeof(txPacketCount) +
            sizeof(txByteCount) +
            sizeof(collisionCount) +
            sizeof(errorCount);

    return size;
}

}
}
