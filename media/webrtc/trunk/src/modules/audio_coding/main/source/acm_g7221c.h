/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_MODULES_AUDIO_CODING_MAIN_SOURCE_ACM_G722_1C_H_
#define WEBRTC_MODULES_AUDIO_CODING_MAIN_SOURCE_ACM_G722_1C_H_

#include "acm_generic_codec.h"

// forward declaration
struct G722_1C_24_encinst_t_;
struct G722_1C_24_decinst_t_;
struct G722_1C_32_encinst_t_;
struct G722_1C_32_decinst_t_;
struct G722_1C_48_encinst_t_;
struct G722_1C_48_decinst_t_;
struct G722_1_Inst_t_;

namespace webrtc {

class ACMG722_1C : public ACMGenericCodec
{
public:
    ACMG722_1C(WebRtc_Word16 codecID);
    ~ACMG722_1C();
    // for FEC
    ACMGenericCodec* CreateInstance(void);

    WebRtc_Word16 InternalEncode(
        WebRtc_UWord8* bitstream,
        WebRtc_Word16* bitStreamLenByte);

    WebRtc_Word16 InternalInitEncoder(
        WebRtcACMCodecParams *codecParams);

    WebRtc_Word16 InternalInitDecoder(
        WebRtcACMCodecParams *codecParams);

protected:
    WebRtc_Word16 DecodeSafe(
        WebRtc_UWord8* bitStream,
        WebRtc_Word16  bitStreamLenByte,
        WebRtc_Word16* audio,
        WebRtc_Word16* audioSamples,
        WebRtc_Word8*  speechType);

    WebRtc_Word32 CodecDef(
        WebRtcNetEQ_CodecDef& codecDef,
        const CodecInst&      codecInst);

    void DestructEncoderSafe();

    void DestructDecoderSafe();

    WebRtc_Word16 InternalCreateEncoder();

    WebRtc_Word16 InternalCreateDecoder();

    void InternalDestructEncoderInst(
        void* ptrInst);

    WebRtc_Word32    _operationalRate;

    G722_1_Inst_t_*  _encoderInstPtr;
    G722_1_Inst_t_*  _encoderInstPtrRight; //Used in stereo mode
    G722_1_Inst_t_*  _decoderInstPtr;

    // Only one set of these pointer is valid at any instance
    G722_1C_24_encinst_t_* _encoderInst24Ptr;
    G722_1C_24_encinst_t_* _encoderInst24PtrR;
    G722_1C_32_encinst_t_* _encoderInst32Ptr;
    G722_1C_32_encinst_t_* _encoderInst32PtrR;
    G722_1C_48_encinst_t_* _encoderInst48Ptr;
    G722_1C_48_encinst_t_* _encoderInst48PtrR;

    // Only one of these pointer is valid at any instance
    G722_1C_24_decinst_t_* _decoderInst24Ptr;
    G722_1C_32_decinst_t_* _decoderInst32Ptr;
    G722_1C_48_decinst_t_* _decoderInst48Ptr;
};

} // namespace webrtc;

#endif  // WEBRTC_MODULES_AUDIO_CODING_MAIN_SOURCE_ACM_G722_1C_H_
