//
//  AgoraRteMediaObjectProtocols.h
//  AgoraRte
//
//  Created by Cavan on 2023/4/17.
//

#import <Foundation/Foundation.h>
#import "AgoraRteMediaRawDataProtocols.h"
#import "AgoraRteObjects.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AgoraRteCameraVideoTrackObserver <NSObject>
- (void)onCameraStateUpdatedWithDeviceId:(NSString *)deviceId
                                   state:(AgoraRteMediaSourceState)state;
@end

@protocol AgoraRteCameraVideoTrack
- (AgoraRteMediaSourceState)getState;
- (AgoraRteVideoSourceType)getVideoSourceType;
- (NSString *)getDeviceId;

- (AgoraRteError * _Nullable)setCaptureParams:(AgoraRteCameraCaptureParams *)params;

- (AgoraRteError * _Nullable)startPreview:(AgoraRteVideoRenderConfig *)config
                                     view:(VIEW_CLASS *)view;

- (AgoraRteError * _Nullable)stopPreview:(VIEW_CLASS *)view;

- (AgoraRteError * _Nullable)updatePreview:(AgoraRteVideoRenderConfig *)config;

- (AgoraRteError * _Nullable)switchPosition;
- (AgoraRteCameraPosition)getPosition;

- (AgoraRteError * _Nullable)start;
- (AgoraRteError * _Nullable)stop;

- (BOOL)isCapabilitySupported;

- (AgoraRteError * _Nullable)startTest;
- (AgoraRteError * _Nullable)stopTest;

- (void)addObserver:(id<AgoraRteCameraVideoTrackObserver>)observer;
- (void)removeObserver:(id<AgoraRteCameraVideoTrackObserver>)observer;
@end

@protocol AgoraRteMicrophoneAudioTrackObserver <NSObject>
- (void)onMicrophoneStateUpdatedWithDeviceId:(NSString *)deviceId
                                       state:(AgoraRteMediaSourceState)state;
                        
- (void)onMicrophoneVolumeIndicationUpdatedWithDeviceId:(NSString *)deviceId
                                                 volume:(NSUInteger)volume;
@end

@protocol AgoraRteMicrophoneAudioTrack
- (AgoraRteMediaSourceState)getState;
- (AgoraRteAudioSourceType)getAudioSourceType;
- (NSString *)getDeviceId;

- (AgoraRteError * _Nullable)setAudioRawDataConfig:(AgoraRteAudioRawDataConfig *)config;
- (AgoraRteError * _Nullable)addAudioRawDataObserver:(id<AgoraRteRecordAudioRawDataObserver>)observer NS_SWIFT_NAME(addAudioRawData(_:));
- (AgoraRteError * _Nullable)removeAudioRawDataObserver:(id<AgoraRteRecordAudioRawDataObserver>)observer NS_SWIFT_NAME(removeAudioRawData(_:));

- (AgoraRteError * _Nullable)start;
- (AgoraRteError * _Nullable)stop;

- (BOOL)isCapabilitySupported;

- (AgoraRteError * _Nullable)startTest;
- (AgoraRteError * _Nullable)stopTest;

- (void)addObserver:(id<AgoraRteMicrophoneAudioTrackObserver>)observer;
- (void)removeObserver:(id<AgoraRteMicrophoneAudioTrackObserver>)observer;
@end

@protocol AgoraRteScreenTrackObserver <NSObject>
- (void)onScreenCaptureStateUpdatedWithDeviceId:(NSString *)deviceId
                                          state:(AgoraRteMediaSourceState)state;
@end

@protocol AgoraRteScreenTrack
- (NSString *)getSourceId;
- (AgoraRteMediaSourceState)getState;
- (AgoraRteVideoSourceType)getVideoSourceType;

- (AgoraRteError * _Nullable)start:(AgoraRteScreenCaptureParams *)params;
- (AgoraRteError * _Nullable)stop;
- (AgoraRteError * _Nullable)updateCapture:(BOOL)hasAudio;

- (BOOL)isCapabilitySupported;

- (void)addObserver:(id<AgoraRteScreenTrackObserver>)observer;
- (void)removeObserver:(id<AgoraRteScreenTrackObserver>)observer;
@end

@protocol AgoraRteVideoEffectEnhancer
- (AgoraRteError * _Nullable)enableLowlightEnhancement:(BOOL)enable;
- (AgoraRteError * _Nullable)enableVideoDenoiser:(BOOL)enable;
- (AgoraRteError * _Nullable)enableHardwareEncoder:(BOOL)enable;
- (AgoraRteError * _Nullable)setBeautyOptions:(BOOL)enable
                                      options:(AgoraRteBeautyOptions * _Nullable)options;
- (AgoraRteError * _Nullable)setVirtualBackgroundOptions:(BOOL)enable
                                                 options:(AgoraRteVirtualBackgroundOptions * _Nullable)options;
- (BOOL)checkSatisfyVirtualBackgroundRequirements;
- (BOOL)checkSatisfyBeautyRequirements;
@end

@protocol AgoraRteAudioEffectEnhancer
- (AgoraRteError * _Nullable)enableAiDenoiser:(BOOL)enable;
- (AgoraRteError * _Nullable)setAiDenoiseLevel:(AgoraRteAiDenoiseLevel)level;
- (AgoraRteError * _Nullable)enableHiFiMode:(BOOL)enable;
- (AgoraRteError * _Nullable)enableEchoCancellation:(BOOL)enable;
- (AgoraRteError * _Nullable)enableStereoMode:(BOOL)enable;
- (AgoraRteError * _Nullable)enableOriginalSoundMode:(BOOL)enable;
@end

@protocol AgoraRteMediaControlObserver <NSObject>
- (void)onLocalOutputVolumeIndicationUpdated:(NSUInteger)indication;
- (void)onLocalAudioOutputRoutingUpdated:(AgoraRteAudioOutputRouting)routing;
@end

@protocol AgoraRteMediaControlTrackObserver <NSObject>
- (void)onVideoTrackStateUpdatedWithSourceId:(NSString *)sourceId
                                        type:(AgoraRteVideoSourceType)type
                                       state:(AgoraRteMediaSourceState)state;

- (void)onAudioTrackStateUpdatedWithSourceId:(NSString *)sourceId
                                        type:(AgoraRteAudioSourceType)type
                                       state:(AgoraRteMediaSourceState)state;
@end

@protocol AgoraRteMediaControl <NSObject>
- (NSArray<AgoraRteDeviceInfo *> * _Nullable)getCameraList;
- (NSArray<AgoraRteDeviceInfo *> * _Nullable)getMicrophoneList;
- (NSArray<AgoraRteDeviceInfo *> * _Nullable)getScreenList;

- (NSObject<AgoraRteCameraVideoTrack> * _Nullable)getCameraVideoTrack:(NSString *)deviceId;
- (NSObject<AgoraRteMicrophoneAudioTrack> * _Nullable)getMicrophoneAudioTrack:(NSString *)deviceId;
- (NSObject<AgoraRteScreenTrack> * _Nullable)getScreenTrack;

- (NSObject<AgoraRteAudioEffectEnhancer> * _Nullable)getAudioEffectEnhancer;
- (NSObject<AgoraRteVideoEffectEnhancer> * _Nullable)getVideoEffectEnhancer;

- (BOOL)isCapabilitySupported:(AgoraRteCapability)capability;

- (AgoraRteError * _Nullable)setEnableSpeaker:(BOOL)enable;
- (AgoraRteError * _Nullable)adjustOutputVolume:(NSUInteger)volume;
- (AgoraRteAudioOutputRouting)getAudioOutputRouting;

- (void)addObserver:(id<AgoraRteMediaControlObserver>)observer;
- (void)removeObserver:(id<AgoraRteMediaControlObserver>)observer;

- (void)addTrackObserver:(NSObject<AgoraRteMediaControlTrackObserver> *)observer;
- (void)removeTrackObserver:(NSObject<AgoraRteMediaControlTrackObserver> *)observer;
@end

NS_ASSUME_NONNULL_END
