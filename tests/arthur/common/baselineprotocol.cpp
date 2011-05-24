begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"baselineprotocol.h"
end_include
begin_include
include|#
directive|include
file|<QLibraryInfo>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QBuffer>
end_include
begin_include
include|#
directive|include
file|<QHostInfo>
end_include
begin_include
include|#
directive|include
file|<QSysInfo>
end_include
begin_include
include|#
directive|include
file|<QProcess>
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QTime>
end_include
begin_include
include|#
directive|include
file|<QPointer>
end_include
begin_decl_stmt
specifier|const
name|QString
name|PI_TestCase
argument_list|(
name|QLS
argument_list|(
literal|"TestCase"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_HostName
argument_list|(
name|QLS
argument_list|(
literal|"HostName"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_HostAddress
argument_list|(
name|QLS
argument_list|(
literal|"HostAddress"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_OSName
argument_list|(
name|QLS
argument_list|(
literal|"OSName"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_OSVersion
argument_list|(
name|QLS
argument_list|(
literal|"OSVersion"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_QtVersion
argument_list|(
name|QLS
argument_list|(
literal|"QtVersion"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_BuildKey
argument_list|(
name|QLS
argument_list|(
literal|"BuildKey"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_GitCommit
argument_list|(
name|QLS
argument_list|(
literal|"GitCommit"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_QMakeSpec
argument_list|(
name|QLS
argument_list|(
literal|"QMakeSpec"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_PulseGitBranch
argument_list|(
name|QLS
argument_list|(
literal|"PulseGitBranch"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QString
name|PI_PulseTestrBranch
argument_list|(
name|QLS
argument_list|(
literal|"PulseTestrBranch"
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QMAKESPEC
end_ifndef
begin_define
DECL|macro|QMAKESPEC
define|#
directive|define
name|QMAKESPEC
value|"Unknown"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtCore/qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_if
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|sysSleep
name|void
name|BaselineProtocol
operator|::
name|sysSleep
parameter_list|(
name|int
name|ms
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|Sleep
argument_list|(
name|DWORD
argument_list|(
name|ms
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|struct
name|timespec
name|ts
init|=
block|{
name|ms
operator|/
literal|1000
block|,
operator|(
name|ms
operator|%
literal|1000
operator|)
operator|*
literal|1000
operator|*
literal|1000
block|}
decl_stmt|;
name|nanosleep
argument_list|(
operator|&
name|ts
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_constructor
DECL|function|PlatformInfo
name|PlatformInfo
operator|::
name|PlatformInfo
parameter_list|()
member_init_list|:
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
argument_list|()
member_init_list|,
name|replaceDefault
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|localHostInfo
name|PlatformInfo
name|PlatformInfo
operator|::
name|localHostInfo
parameter_list|()
block|{
name|PlatformInfo
name|pi
decl_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_HostName
argument_list|,
name|QHostInfo
operator|::
name|localHostName
argument_list|()
argument_list|)
expr_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_QtVersion
argument_list|,
name|QLS
argument_list|(
name|qVersion
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_QMakeSpec
argument_list|,
name|QString
argument_list|(
name|QLS
argument_list|(
name|QMAKESPEC
argument_list|)
argument_list|)
operator|.
name|remove
argument_list|(
name|QRegExp
argument_list|(
name|QLS
argument_list|(
literal|"^.*mkspecs/"
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_BuildKey
argument_list|,
name|QLibraryInfo
operator|::
name|buildKey
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSName
argument_list|,
name|QLS
argument_list|(
literal|"Linux"
argument_list|)
argument_list|)
expr_stmt|;
name|QProcess
name|uname
decl_stmt|;
name|uname
operator|.
name|start
argument_list|(
name|QLS
argument_list|(
literal|"uname"
argument_list|)
argument_list|,
name|QStringList
argument_list|()
operator|<<
name|QLS
argument_list|(
literal|"-r"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|uname
operator|.
name|waitForFinished
argument_list|(
literal|3000
argument_list|)
condition|)
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSVersion
argument_list|,
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|uname
operator|.
name|readAllStandardOutput
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
operator|.
name|simplified
argument_list|()
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSName
argument_list|,
name|QLS
argument_list|(
literal|"WinCE"
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSVersion
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|QSysInfo
operator|::
name|windowsVersion
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSName
argument_list|,
name|QLS
argument_list|(
literal|"Windows"
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSVersion
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|QSysInfo
operator|::
name|windowsVersion
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSName
argument_list|,
name|QLS
argument_list|(
literal|"MacOS"
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSVersion
argument_list|,
name|QString
operator|::
name|number
argument_list|(
name|qMacVersion
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|pi
operator|.
name|insert
argument_list|(
name|PI_OSName
argument_list|,
name|QLS
argument_list|(
literal|"Symbian"
argument_list|)
argument_list|)
expr_stmt|;
name|pi
operator|.
name|insert
argument_list|(
argument|PI_OSVersion
argument_list|,
argument|QString::number(QSysInfo::symbianVersion());
else|#
directive|else
argument|pi.insert(PI_OSName, QLS(
literal|"Other"
argument|));
endif|#
directive|endif
argument|QProcess git;     QString cmd;     QStringList args;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
argument|cmd = QLS(
literal|"cmd.exe"
argument|);     args<< QLS(
literal|"/c"
argument|)<< QLS(
literal|"git"
argument|);
else|#
directive|else
argument|cmd = QLS(
literal|"git"
argument|);
endif|#
directive|endif
argument|args<< QLS(
literal|"log"
argument|)<< QLS(
literal|"--max-count=1"
argument|)<< QLS(
literal|"--pretty=%H [%an] [%ad] %s"
argument|);     git.start(cmd, args);     git.waitForFinished(
literal|3000
argument|);     if (!git.exitCode())         pi.insert(PI_GitCommit, QString::fromLocal8Bit(git.readAllStandardOutput().constData()).simplified());     else         pi.insert(PI_GitCommit, QLS(
literal|"Unknown"
argument|));      QByteArray gb = qgetenv(
literal|"PULSE_GIT_BRANCH"
argument|);     if (!gb.isEmpty())         pi.insert(PI_PulseGitBranch, QString::fromLatin1(gb));     QByteArray tb = qgetenv(
literal|"PULSE_TESTR_BRANCH"
argument|);     if (!tb.isEmpty())         pi.insert(PI_PulseTestrBranch, QString::fromLatin1(tb));      return pi; }   PlatformInfo::PlatformInfo(const PlatformInfo&other)     : QMap<QString
argument_list|,
argument|QString>(other) {     sigKeys = other.sigKeys;     replaceDefault = other.replaceDefault; }   PlatformInfo&PlatformInfo::operator=(const PlatformInfo&other) {     QMap<QString
argument_list|,
argument|QString>::operator=(other);     sigKeys = other.sigKeys;     replaceDefault = other.replaceDefault;     return *this; }   void PlatformInfo::addSignificantKeys(const QStringList&keys, bool replaceDefaultKeys) {     sigKeys = keys;     replaceDefault = replaceDefaultKeys; }   QStringList PlatformInfo::addedKeys() const {     return sigKeys; }   bool PlatformInfo::addedKeysReplaceDefault() const {     return replaceDefault; }   QDataStream& operator<< (QDataStream&stream, const PlatformInfo&pi) {     stream<< static_cast<const QMap<QString
argument_list|,
argument|QString>&>(pi);     stream<< pi.sigKeys<< pi.replaceDefault;     return stream; }   QDataStream& operator>> (QDataStream&stream, PlatformInfo&pi) {     stream>> static_cast<QMap<QString
argument_list|,
argument|QString>&>(pi);     stream>> pi.sigKeys>> pi.replaceDefault;     return stream; }   ImageItem&ImageItem::operator=(const ImageItem&other) {     testFunction = other.testFunction;     itemName = other.itemName;     itemChecksum = other.itemChecksum;     status = other.status;     image = other.image;     imageChecksums = other.imageChecksums;     return *this; }
comment|// Defined in lookup3.c:
argument|void hashword2 ( const quint32 *k,
comment|/* the key, an array of quint32 values */
argument|size_t         length,
comment|/* the length of the key, in quint32s */
argument|quint32       *pc,
comment|/* IN: seed OUT: primary hash value */
argument|quint32       *pb);
comment|/* IN: more seed OUT: secondary hash value */
argument|quint64 ImageItem::computeChecksum(const QImage&image) {     QImage img(image);     const int bpl = img.bytesPerLine();     const int padBytes = bpl - (img.width() * img.depth() /
literal|8
argument|);     if (padBytes) {         uchar *p = img.bits() + bpl - padBytes;         const int h = img.height();         for (int y =
literal|0
argument|; y< h; ++y) {             qMemSet(p,
literal|0
argument|, padBytes);             p += bpl;         }     }      quint32 h1 =
literal|0xfeedbacc
argument|;     quint32 h2 =
literal|0x21604894
argument|;     hashword2((const quint32 *)img.constBits(), img.byteCount()/
literal|4
argument|,&h1,&h2);     return (quint64(h1)<<
literal|32
argument|) | h2; }
if|#
directive|if
literal|0
argument|QString ImageItem::engineAsString() const {     switch (engine) {     case Raster:         return QLS("Raster");         break;     case OpenGL:         return QLS("OpenGL");         break;     default:         break;     }     return QLS("Unknown"); }  QString ImageItem::formatAsString() const {     static const int numFormats = 16;     static const char *formatNames[numFormats] = {         "Invalid",         "Mono",         "MonoLSB",         "Indexed8",         "RGB32",         "ARGB32",         "ARGB32-Premult",         "RGB16",         "ARGB8565-Premult",         "RGB666",         "ARGB6666-Premult",         "RGB555",         "ARGB8555-Premult",         "RGB888",         "RGB444",         "ARGB4444-Premult"     };     if (renderFormat< 0 || renderFormat>= numFormats)         return QLS("UnknownFormat");     return QLS(formatNames[renderFormat]); }
endif|#
directive|endif
argument|void ImageItem::writeImageToStream(QDataStream&out) const {     if (image.isNull() || image.format() == QImage::Format_Invalid) {         out<< quint8(
literal|0
argument|);         return;     }     out<< quint8(
literal|'Q'
argument|)<< quint8(image.format());     out<< quint8(QSysInfo::ByteOrder)<< quint8(
literal|0
argument|);
comment|// pad to multiple of 4 bytes
argument|out<< quint32(image.width())<< quint32(image.height())<< quint32(image.bytesPerLine());     out<< qCompress((const uchar *)image.constBits(), image.byteCount());
comment|//# can be followed by colormap for formats that use it
argument|}  void ImageItem::readImageFromStream(QDataStream&in) {     quint8 hdr
argument_list|,
argument|fmt
argument_list|,
argument|endian
argument_list|,
argument|pad;     quint32 width
argument_list|,
argument|height
argument_list|,
argument|bpl;     QByteArray data;      in>> hdr;     if (hdr !=
literal|'Q'
argument|) {         image = QImage();         return;     }     in>> fmt>> endian>> pad;     if (!fmt || fmt>= QImage::NImageFormats) {         image = QImage();         return;     }     if (endian != QSysInfo::ByteOrder) {         qWarning(
literal|"ImageItem cannot read streamed image with different endianness"
argument|);         image = QImage();         return;     }     in>> width>> height>> bpl;     in>> data;     data = qUncompress(data);     QImage res((const uchar *)data.constData(), width, height, bpl, QImage::Format(fmt));     image = res.copy();
comment|//# yuck, seems there is currently no way to avoid data copy
argument|}  QDataStream& operator<< (QDataStream&stream, const ImageItem&ii) {     stream<< ii.testFunction<< ii.itemName<< ii.itemChecksum<< quint8(ii.status)<< ii.imageChecksums<< ii.misc;     ii.writeImageToStream(stream);     return stream; }  QDataStream& operator>> (QDataStream&stream, ImageItem&ii) {     quint8 encStatus;     stream>> ii.testFunction>> ii.itemName>> ii.itemChecksum>> encStatus>> ii.imageChecksums>> ii.misc;     ii.status = ImageItem::ItemStatus(encStatus);     ii.readImageFromStream(stream);     return stream; }  BaselineProtocol::BaselineProtocol() { }  BaselineProtocol::~BaselineProtocol() {     socket.close();     if (socket.state() != QTcpSocket::UnconnectedState)         socket.waitForDisconnected(Timeout); }   bool BaselineProtocol::connect(const QString&testCase, bool *dryrun) {     errMsg.clear();     QByteArray serverName(qgetenv(
literal|"QT_LANCELOT_SERVER"
argument|));     if (serverName.isNull())         serverName =
literal|"lancelot.test.qt.nokia.com"
argument|;      socket.connectToHost(serverName, ServerPort);     if (!socket.waitForConnected(Timeout)) {         sysSleep(Timeout);
comment|// Wait a bit and try again, the server might just be restarting
argument|if (!socket.waitForConnected(Timeout)) {             errMsg += QLS(
literal|"TCP connectToHost failed. Host:"
argument|) + serverName + QLS(
literal|" port:"
argument|) + QString::number(ServerPort);             return
literal|false
argument|;         }     }      PlatformInfo pi = PlatformInfo::localHostInfo();     pi.insert(PI_TestCase, testCase);     QByteArray block;     QDataStream ds(&block, QIODevice::ReadWrite);     ds<< pi;     if (!sendBlock(AcceptPlatformInfo, block)) {         errMsg += QLS(
literal|"Failed to send data to server."
argument|);         return
literal|false
argument|;     }      Command cmd = UnknownError;     if (!receiveBlock(&cmd,&block)) {         errMsg.prepend(QLS(
literal|"Failed to get response from server. "
argument|));         return
literal|false
argument|;     }      if (cmd == Abort) {         errMsg += QLS(
literal|"Server rejected connection. Reason: "
argument|) + QString::fromLatin1(block);         return
literal|false
argument|;     }      if (dryrun)         *dryrun = (cmd == DoDryRun);      if (cmd != Ack&& cmd != DoDryRun) {         errMsg += QLS(
literal|"Unexpected response from server."
argument|);         return
literal|false
argument|;     }      return
literal|true
argument|; }   bool BaselineProtocol::acceptConnection(PlatformInfo *pi) {     errMsg.clear();      QByteArray block;     Command cmd = AcceptPlatformInfo;     if (!receiveBlock(&cmd,&block) || cmd != AcceptPlatformInfo)         return
literal|false
argument|;      if (pi) {         QDataStream ds(block);         ds>> *pi;         pi->insert(PI_HostAddress, socket.peerAddress().toString());     }      return
literal|true
argument|; }   bool BaselineProtocol::requestBaselineChecksums(const QString&testFunction, ImageItemList *itemList) {     errMsg.clear();     if (!itemList)         return
literal|false
argument|;      for(ImageItemList::iterator it = itemList->begin(); it != itemList->end(); it++)         it->testFunction = testFunction;      QByteArray block;     QDataStream ds(&block, QIODevice::WriteOnly);     ds<< *itemList;     if (!sendBlock(RequestBaselineChecksums, block))         return
literal|false
argument|;      Command cmd;     QByteArray rcvBlock;     if (!receiveBlock(&cmd,&rcvBlock) || cmd != BaselineProtocol::Ack)         return
literal|false
argument|;     QDataStream rds(&rcvBlock, QIODevice::ReadOnly);     rds>> *itemList;     return
literal|true
argument|; }   bool BaselineProtocol::submitNewBaseline(const ImageItem&item, QByteArray *serverMsg) {     Command cmd;     return (sendItem(AcceptNewBaseline, item)&& receiveBlock(&cmd, serverMsg)&& cmd == Ack); }   bool BaselineProtocol::submitMismatch(const ImageItem&item, QByteArray *serverMsg) {     Command cmd;     return (sendItem(AcceptMismatch, item)&& receiveBlock(&cmd, serverMsg)&& cmd == Ack); }   bool BaselineProtocol::sendItem(Command cmd, const ImageItem&item) {     errMsg.clear();     QBuffer buf;     buf.open(QIODevice::WriteOnly);     QDataStream ds(&buf);     ds<< item;     if (!sendBlock(cmd, buf.data())) {         errMsg.prepend(QLS(
literal|"Failed to submit image to server. "
argument|));         return
literal|false
argument|;     }     return
literal|true
argument|; }   bool BaselineProtocol::sendBlock(Command cmd, const QByteArray&block) {     QDataStream s(&socket);
comment|// TBD: set qds version as a constant
argument|s<< quint16(ProtocolVersion)<< quint16(cmd);     s.writeBytes(block.constData(), block.size());     return
literal|true
argument|; }   bool BaselineProtocol::receiveBlock(Command *cmd, QByteArray *block) {     while (socket.bytesAvailable()< int(
literal|2
argument|*sizeof(quint16) + sizeof(quint32))) {         if (!socket.waitForReadyRead(Timeout))             return
literal|false
argument|;     }     QDataStream ds(&socket);     quint16 rcvProtocolVersion
argument_list|,
argument|rcvCmd;     ds>> rcvProtocolVersion>> rcvCmd;     if (rcvProtocolVersion != ProtocolVersion) {         errMsg = QLS(
literal|"Baseline protocol version mismatch, received:"
argument|) + QString::number(rcvProtocolVersion)                 + QLS(
literal|" expected:"
argument|) + QString::number(ProtocolVersion);         return
literal|false
argument|;     }     if (cmd)         *cmd = Command(rcvCmd);      QByteArray uMsg;     quint32 remaining;     ds>> remaining;     uMsg.resize(remaining);     int got =
literal|0
argument|;     char* uMsgBuf = uMsg.data();     do {         got = ds.readRawData(uMsgBuf, remaining);         remaining -= got;         uMsgBuf += got;     } while (remaining&& got>=
literal|0
argument|&& socket.waitForReadyRead(Timeout));      if (got<
literal|0
argument|)         return
literal|false
argument|;      if (block)         *block = uMsg;      return
literal|true
argument|; }   QString BaselineProtocol::errorMessage() {     QString ret = errMsg;     if (socket.error()>=
literal|0
argument|)         ret += QLS(
literal|" Socket state: "
argument|) + socket.errorString();     return ret; }
end_function
end_unit
