//
//  AgoraRte
//
//  Created by Cavan on 2020/11/14.
//

#import <AgoraFoundation/AgoraFoundation-Swift.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef AgoraDomainNamePoolRegion AgoraRteRegion;

typedef NS_ENUM(NSUInteger, AgoraRteConnectionState) {
    AgoraRteConnectionStateDisconnected = 0,
    AgoraRteConnectionStateConnecting   = 1,
    AgoraRteConnectionStateConnected    = 2,
    AgoraRteConnectionStateAborted      = 3
};

typedef NS_ENUM(NSUInteger, AgoraRteStreamType) {
    AgoraRteStreamTypeNone          = 0,
    AgoraRteStreamTypeAudio         = 1,
    AgoraRteStreamTypeVideo         = 2,
    AgoraRteStreamTypeBoth          = 3
};

typedef NS_ENUM(NSUInteger, AgoraRteVideoSourceType) {
    AgoraRteVideoSourceTypeNone          = 0,
    AgoraRteVideoSourceTypeCamera        = 1,
    AgoraRteVideoSourceTypeScreenSharing = 2
};

typedef NS_ENUM(NSUInteger, AgoraRteAudioSourceType) {
    AgoraRteAudioSourceTypeNone          = 0,
    AgoraRteAudioSourceTypeMicrophone    = 1,
    AgoraRteAudioSourceTypeLoopback      = 2
};

typedef NS_ENUM(NSUInteger, AgoraRteMediaSourceState) {
    AgoraRteMediaSourceStateError = -1,
    AgoraRteMediaSourceStateClose = 0,
    AgoraRteMediaSourceStateOpen  = 1
};

typedef NS_ENUM(NSUInteger, AgoraRteCapability) {
    AgoraRteCapabilityScreenCapture = 0,
    AgoraRteCapabilityOther         = 1,
};

typedef NS_ENUM(NSUInteger, AgoraRteVideoRenderMode) {
    AgoraRteVideoRenderModeHidden   = 1,
    AgoraRteVideoRenderModeFit      = 2
};

typedef NS_ENUM(NSUInteger, AgoraRteStreamState) {
    AgoraRteStreamStateStopped  = 0,
    AgoraRteStreamStateStarting = 1,
    AgoraRteStreamStateRunning  = 2,
    AgoraRteStreamStateFrozen   = 3,
    AgoraRteStreamStateFailed   = 4
};

typedef NS_ENUM(NSUInteger, AgoraRteCameraPosition) {
    AgoraRteCameraPositionFront = 0,
    AgoraRteCameraPositionBack  = 1
};

typedef NS_ENUM(NSUInteger, AgoraRteStreamLatencyLevel) {
    AgoraRteStreamLatencyLevelLow      = 1,
    AgoraRteStreamLatencyLevelUltraLow = 2
};

typedef NS_ENUM(NSUInteger, AgoraRteVideoOutputOrientationMode) {
    AgoraRteVideoOutputOrientationModeAdaptative     = 0,
    AgoraRteVideoOutputOrientationModeFixedLandScape = 1,
    AgoraRteVideoOutputOrientationModeFixedPortrait  = 2
};

typedef NS_ENUM(NSUInteger, AgoraRteDegradationPreference) {
    AgoraRteDegradationPreferenceQuality   = 0,
    AgoraRteDegradationPreferenceFrameRate = 1,
    AgoraRteDegradationPreferenceBalanced  = 2
};

typedef NS_ENUM(NSUInteger, AgoraRteMediaPlayerState) {
    AgoraRteMediaPlayerStatePlaying = 1,
    AgoraRteMediaPlayerStatePause   = 2,
    AgoraRteMediaPlayerStateStopped = 3,
    AgoraRteMediaPlayerStateFinish  = 4
};

typedef NS_ENUM(NSInteger, AgoraRteAudioOutputRouting) {
    AgoraRteAudioOutputRoutingDefault = -1,
    AgoraRteAudioOutputRoutingHeadset = 0,
    AgoraRteAudioOutputRoutingEarpiece = 1,
    AgoraRteAudioOutputRoutingSpeakerphone = 3,
    AgoraRteAudioOutputRoutingBluetoothDeviceHfp = 5,
    AgoraRteAudioOutputRoutingAirPlay = 9,
    AgoraRteAudioOutputRoutingBluetoothDeviceA2dp = 10
};

typedef NS_ENUM(NSInteger, AgoraRteAudioProfile) {
    AgoraRteAudioProfileDefault                = 0,
    AgoraRteAudioProfileSpeechStandard         = 1,
    AgoraRteAudioProfileMusicStandard          = 2,
    AgoraRteAudioProfileMusicStandardStereo    = 3,
    AgoraRteAudioProfileMusicHighQuality       = 4,
    AgoraRteAudioProfileMusicHighQualityStereo = 5
};

typedef NS_ENUM(NSInteger, AgoraRteAudioScenario) {
    AgoraRteAudioScenarioDefault        = 0,
    AgoraRteAudioScenarioGameStreaming  = 3,
    AgoraRteAudioScenarioChatRoom       = 5,
    AgoraRteAudioScenarioChorus         = 7,
    AgoraRteAudioScenarioMeeting        = 8
};

typedef NS_ENUM(NSUInteger, AgoraRteNetworkQuality) {
    /** The network quality is unknown. */
    AgoraRteNetworkQualityUnknown     = 0,
    /**  The network quality is excellent. */
    AgoraRteNetworkQualityExcellent   = 1,
    /** The network quality is quite good, but the bitrate may be slightly lower than excellent. */
    AgoraRteNetworkQualityGood        = 2,
    /** Users can feel the communication slightly impaired. */
    AgoraRteNetworkQualityPoor        = 3,
    /** Users can communicate only not very smoothly. */
    AgoraRteNetworkQualityBad         = 4,
     /** The network quality is so bad that users can hardly communicate. */
    AgoraRteNetworkQualityVBad        = 5,
     /** The network is disconnected and users cannot communicate at all. */
    AgoraRteNetworkQualityDown        = 6,
     /** Users cannot detect the network quality. (Not in use.) */
    AgoraRteNetworkQualityUnsupported = 7,
     /** Detecting the network quality. */
    AgoraRteNetworkQualityDetecting   = 8
};

typedef NS_ENUM(NSInteger, AgoraRteVideoStreamType) {
    AgoraRteVideoStreamTypeHigh = 0,
    AgoraRteVideoStreamTypeLow  = 1
};

typedef NS_ENUM(NSInteger, AgoraRteMediaRawDataOperationMode) {
    AgoraRteMediaRawDataOperationModeReadOnly  = 0,
    AgoraRteMediaRawDataOperationModeWriteOnly = 1,
    AgoraRteMediaRawDataOperationModeReadWrite = 2
};

typedef NS_ENUM(NSInteger, AgoraRteAudioRawDataOutputPosition) {
    AgoraRteAudioRawDataOutputPositionPlayback    = 1,
    AgoraRteAudioRawDataOutputPositionMixed       = 4,
    AgoraRteAudioRawDataOutputPositionBeforeMixed = 8
};

typedef NS_ENUM(NSInteger, AgoraRteAudioRawDataPosition) {
    AgoraRteAudioRawDataPositionPlayback    = 1,
    AgoraRteAudioRawDataPositionRecord      = 2,
    AgoraRteAudioRawDataPositionMixed       = 4,
    AgoraRteAudioRawDataPositionBeforeMixed = 8
};

typedef NS_ENUM(NSInteger, AgoraRteUserUpdatedReason) {
    AgoraRteUserUpdatedReasonName        = 1,
    AgoraRteUserUpdatedReasonRole        = 2
};

typedef NS_ENUM(NSInteger, AgoraRteStreamPrivilegeOperation) {
    AgoraRteStreamPrivilegeOperationNoOperation        = 0,
    AgoraRteStreamPrivilegeOperationHasPrivilege       = 1,
    AgoraRteStreamPrivilegeOperationNoPrivilege        = 2
};

typedef NS_OPTIONS(NSUInteger, AgoraRteStreamPrivilegeVideoSourceType) {
    AgoraRteStreamPrivilegeVideoSourceTypeCamera = 1 << 0,
    AgoraRteStreamPrivilegeVideoSourceTypeScreen = 1 << 1
};

typedef NS_OPTIONS(NSUInteger, AgoraRteStreamPrivilegeAudioSourceType) {
    AgoraRteStreamPrivilegeAudioSourceTypeMicrophone = 1 << 0,
    AgoraRteStreamPrivilegeAudioSourceTypeLoopback   = 1 << 1
};

typedef NS_ENUM(NSUInteger, AgoraRteRoomConnectorType) {
    AgoraRteRoomConnectorTypeNone = 0,
    AgoraRteRoomConnectorTypePSTN = 1,
    AgoraRteRoomConnectorTypeH323 = 2,
    AgoraRteRoomConnectorTypeSIP  = 3
};

typedef NS_ENUM(NSUInteger, AgoraRteVirtualBackgroundSourceType) {
    AgoraRteVirtualBackgroundSourceTypeNone  = 0,
    AgoraRteVirtualBackgroundSourceTypeColor = 1,
    AgoraRteVirtualBackgroundSourceTypeImg   = 2,
    AgoraRteVirtualBackgroundSourceTypeBlur  = 3,
    AgoraRteVirtualBackgroundSourceTypeVideo = 4,
};

typedef NS_ENUM(NSUInteger, AgoraRteAiDenoiseLevel) {
    AgoraRteAiDenoiseLevelHigh   = 0,
    AgoraRteAiDenoiseLevelMedium = 1,
    AgoraRteAiDenoiseLevelLow    = 2
};

typedef NS_ENUM(NSUInteger, AgoraRteLighteningContrastLevel) {
    AgoraRteLighteningContrastLevelLow    = 0,
    AgoraRteLighteningContrastLevelNormal = 1,
    AgoraRteLighteningContrastLevelHigh   = 2
};

NS_ASSUME_NONNULL_END
