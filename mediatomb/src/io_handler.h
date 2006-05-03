/*  io_handler.h - this file is part of MediaTomb.
                                                                                
    Copyright (C) 2005 Gena Batyan <bgeradz@deadlock.dhs.org>,
                       Sergey Bostandzhyan <jin@deadlock.dhs.org>
                                                                                
    MediaTomb is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
                                                                                
    MediaTomb is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
                                                                                
    You should have received a copy of the GNU General Public License
    along with MediaTomb; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/// \file io_handler.h
/// \brief Definitoin for the IOHandler class.
#ifndef __IO_HANDLER_H__
#define __IO_HANDLER_H__

#include "common.h"
#include "upnp.h"

class IOHandler : public zmm::Object
{
public:
    IOHandler();

    /// \brief Opens a data for the web server.
    /// \param mode in which the data will be opened (we only support UPNP_READ)
    /// \todo Genych, ya tut che to zapamyatowal kak gawno rabotaet? kto filename poluchaet??
    virtual void open(enum UpnpOpenFileMode mode);

    /// \brief Reads previously opened/initialized data sequentially.
    /// \param buf This buffer will be filled by our read functions.
    /// \param length Number of bytes to read.
    virtual int read(char *buf, size_t length);

    /// \brief Writes to previously opened/initialized data sequentially.
    /// \param buf Data to be written.
    /// \param length Number of bytes to write.
    virtual int write(char *buf, size_t length);
                      
    /// \brief Performs a seek on an open/initialized data.
    /// \param offset Number of bytes to move in the buffer. 
    
    /// For seeking forwards
    /// positive values are used, for seeking backwards - negative. \b Offset must
    /// be positive if \b origin is set to \b SEEK_SET
    /// \param whence The position to move relative to. SEEK_CUR to move relative
    /// to current position, SEEK_END to move relative to the end of file,
    /// SEEK_SET to specify an absolute offset.
    virtual void seek(long offset, int whence);

    /// \brief Close/free previously opened/initialized data.
    virtual void close();
};


#endif // __IO_HANDLER_H__
