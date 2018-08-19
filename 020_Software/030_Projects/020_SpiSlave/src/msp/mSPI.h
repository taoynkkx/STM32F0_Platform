#ifndef  __MSPI_H
#define  __MSPI_H

extern void mSPI_masterInit(void);
extern void mSPI_masterSendByteBlocking(unsigned char data);

extern void mSPI_slaveInit(void);
extern void mSPI_hook_slaveDataReceived(unsigned char data);

#endif  //  __MSPI_H
