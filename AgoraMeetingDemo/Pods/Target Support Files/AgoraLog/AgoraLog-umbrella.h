#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "AgoraLogEnums.h"
#import "AgoraLogger.h"
#import "AgoraLogUtils.h"

FOUNDATION_EXPORT double AgoraLogVersionNumber;
FOUNDATION_EXPORT const unsigned char AgoraLogVersionString[];

