//
//  AgoraRte
//
//  Created by Cavan on 2020/11/14.
//

#import <AgoraFoundation/AgoraFoundation-Swift.h>
#import <AgoraLog/AgoraLogger.h>
#import <UIKit/UIKit.h>
#import "AgoraRteEnums.h"

NS_ASSUME_NONNULL_BEGIN

@class AgoraRteVideoEncoderConfig;
@class AgoraRteStreamEncryptionConfig;
@class AgoraRteUserInfo;
@class AgoraRteUserPageResponse;
@class AgoraRteSnapshotInfo;
@class AgoraRteAudioConfig;
@class AgoraRteDualVideoStreamConfig;

#pragma mark - Typedef
typedef UIView VIEW_CLASS;
typedef AgoraError AgoraRteError;

typedef void(^AgoraRteCompletion) (void);
typedef void(^AgoraRteErrorCompletion) (AgoraRteError *error);
typedef void(^AgoraRteUserPageCompletion) (AgoraRteUserPageResponse *response);
typedef void(^AgoraRteStringCompletion) (NSString *);
typedef void(^AgoraRteSnapshotCompletion) (AgoraRteSnapshotInfo *data);
typedef void(^AgoraRteJsonCompletion) (NSDictionary<NSString *, id> * _Nonnull json);

@interface AgoraRteObject : NSObject <AgoraObjectDescription>
- (NSString *)agora_description;
@end

#pragma mark - Input
__attribute__((visibility("default")))
@interface AgoraRteEngineConfig : AgoraRteObject
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *logFilePath;
@property (nonatomic, assign) AgoraConsolePrintType logConsolePrintType;
@property (nonatomic, assign) AgoraRteRegion rteRegion;
@property (nonatomic, assign) AgoraRteRegion rtcRegion;
@property (nonatomic, assign) AgoraRteRegion rtmRegion;
@property (nonatomic, strong) AgoraRteAudioConfig *audioConfig;
@property (nonatomic, strong) NSDictionary<NSString *, id> * parameters;

- (instancetype)initWithAppId:(NSString *)appId
                       userId:(NSString *)userId
                        token:(NSString *)token
                    rteRegion:(AgoraRteRegion)rteRegion
                    rtcRegion:(AgoraRteRegion)rtcRegion
                    rtmRegion:(AgoraRteRegion)rtmRegion
            logFileFolderPath:(NSString *)logFileFolderPath
                  audioConfig:(AgoraRteAudioConfig *)audioConfig;
@end

#pragma mark - Input - Scene
__attribute__((visibility("default")))
@interface AgoraRteSceneConfig : AgoraRteObject
@property (nonatomic, copy) NSString *sceneId;

- (instancetype)initWithSceneId:(NSString *)sceneId;
@end

__attribute__((visibility("default")))
@interface AgoraRteStreamJoinConfig : AgoraRteObject
@property (nonatomic, strong) AgoraRteDualVideoStreamConfig *videoEncoderConfig;
@property (nonatomic, assign) AgoraRteVideoSourceType videoSourceType;
@property (nonatomic, assign) AgoraRteAudioSourceType audioSourceType;
@property (nonatomic, assign) AgoraRteStreamType streamType;
@property (nonatomic, copy, nullable) NSString *videoSourceId;
@property (nonatomic, copy, nullable) NSString *audioSourceId;
@property (nonatomic, copy, nullable) NSString *streamName;

- (instancetype)initWithVideoEncoderConfig:(AgoraRteDualVideoStreamConfig *)videoEncoderConfig
                           videoSourceType:(AgoraRteVideoSourceType)videoSourceType
                           audioSourceType:(AgoraRteAudioSourceType)audioSourceType
                                streamType:(AgoraRteStreamType)streamType
                             videoSourceId:(NSString * _Nullable)videoSourceId
                             audioSourceId:(NSString * _Nullable)audioSourceId
                                streamName:(NSString * _Nullable)streamName;
@end

__attribute__((visibility("default")))
@interface AgoraRteSceneJoinOptions : AgoraRteObject
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *userRole;
@property (nonatomic, strong, nullable) NSDictionary<NSString *, id> *userProperties;
@property (nonatomic, copy) NSString *sceneToken;
@property (nonatomic, strong, nullable) AgoraRteStreamEncryptionConfig *streamEncryptionConfig;
@property (nonatomic, assign) AgoraRteStreamLatencyLevel streamLatency;
@property (nonatomic, strong, nullable) NSArray<AgoraRteStreamJoinConfig *> *createStreamConfigs;

- (instancetype)initWithUserName:(NSString *)userName
                        userRole:(NSString *)userRole
                  userProperties:(NSDictionary<NSString *, id> * _Nullable)userProperties
                      sceneToken:(NSString *)sceneToken
          streamEncryptionConfig:(AgoraRteStreamEncryptionConfig * _Nullable)streamEncryptionConfig
                   streamLatency:(AgoraRteStreamLatencyLevel)streamLatency
             createStreamConfigs:(NSArray<AgoraRteStreamJoinConfig *> * _Nullable)createStreamConfigs;
@end

__attribute__((visibility("default")))
@interface AgoraRteSceneJoinSnapshotOptions : AgoraRteObject
@property (nonatomic, strong) NSDictionary *snapshot;
@property (nonatomic, strong, nullable) AgoraRteStreamEncryptionConfig *streamEncryptionConfig;
@property (nonatomic, assign) AgoraRteStreamLatencyLevel streamLatency;
@property (nonatomic, copy) NSString *sceneToken;
@property (nonatomic, assign) UInt64 timestamp;

- (instancetype)initWithSnapshot:(NSDictionary *)snapshot
          streamEncryptionConfig:(AgoraRteStreamEncryptionConfig * _Nullable)streamEncryptionConfig
                   streamLatency:(AgoraRteStreamLatencyLevel)streamLatency
                      sceneToken:(NSString *)sceneToken
                       timestamp:(UInt64)timestamp;
@end

#pragma mark - Input - User
@interface AgoraRteUserPageParams : AgoraRteObject
@property (nonatomic, assign) NSUInteger pageIndex;
@property (nonatomic, assign) NSUInteger pageSize;

- (instancetype)initWithPageIndex:(NSUInteger)pageIndex
                         pageSize:(NSUInteger)pageSize;
@end

@interface AgoraRteUserPageResponse : AgoraRteObject
@property (nonatomic, strong) NSArray<AgoraRteUserInfo *> *userList;
@property (nonatomic, assign) NSUInteger userCount;

- (instancetype)initWithUserList:(NSArray<AgoraRteUserInfo *> *)userList
                       userCount:(NSUInteger)userCount;
@end

#pragma mark - Input - Stream
__attribute__((visibility("default")))
@interface AgoraRteStreamCreateConfig : AgoraRteObject
@property (nonatomic, copy, nullable) NSString *streamName;
@property (nonatomic, assign) AgoraRteStreamType streamType;
@property (nonatomic, assign) AgoraRteVideoSourceType videoSourceType;
@property (nonatomic, assign) AgoraRteAudioSourceType audioSourceType;
@property (nonatomic, copy) NSString *ownerId;
@property (nonatomic, copy, nullable) NSString *videoSourceId;
@property (nonatomic, copy, nullable) NSString *audioSourceId;

- (instancetype)initWithStreamName:(NSString * _Nullable)streamName
                        streamType:(AgoraRteStreamType)streamType
                   videoSourceType:(AgoraRteVideoSourceType)videoSourceType
                   audioSourceType:(AgoraRteAudioSourceType)audioSourceType
                           ownerId:(NSString *)ownerId
                     videoSourceId:(NSString * _Nullable)videoSourceId
                     audioSourceId:(NSString * _Nullable)audioSourceId;
@end

__attribute__((visibility("default")))
@interface AgoraRteStreamBindConfig : AgoraRteObject
@property (nonatomic, copy) NSString *streamId;
@property (nonatomic, copy, nullable) NSString *videoSourceId;
@property (nonatomic, copy, nullable) NSString *audioSourceId;

- (instancetype)initWithStreamId:(NSString *)streamId
                   videoSourceId:(NSString * _Nullable)videoSourceId
                   audioSourceId:(NSString * _Nullable)audioSourceId;
@end

__attribute__((visibility("default")))
@interface AgoraRteUpdateStreamPrivilege : AgoraRteObject
@property (nonatomic, assign) AgoraRteStreamPrivilegeOperation videoPrivilege;
@property (nonatomic, assign) AgoraRteStreamPrivilegeOperation audioPrivilege;

- (instancetype)initWithVideoPrivilege:(AgoraRteStreamPrivilegeOperation)videoPrivilege
                        audioPrivilege:(AgoraRteStreamPrivilegeOperation)audioPrivilege;
@end

__attribute__((visibility("default")))
@interface AgoraRteUpdateStreamPrivilegeScope : AgoraRteObject
@property (nonatomic, assign) AgoraRteStreamPrivilegeVideoSourceType videoSourceType;
@property (nonatomic, assign) AgoraRteStreamPrivilegeAudioSourceType audioSourceType;
@property (nonatomic, strong) NSArray<NSString *> *targetRoleType;
@property (nonatomic, assign) BOOL targetRoleTypeIsInclude;

- (instancetype)initWithVideoSourceType:(AgoraRteStreamPrivilegeVideoSourceType)videoSourceType
                        audioSourceType:(AgoraRteStreamPrivilegeAudioSourceType)audioSourceType
                         targetRoleType:(NSArray<NSString *> *)targetRoleType
                targetRoleTypeIsInclude:(BOOL)targetRoleTypeIsInclude;
@end

#pragma mark - Input - Media
__attribute__((visibility("default")))
@interface AgoraRteVideoEncoderConfig : AgoraRteObject
@property (nonatomic, assign) CGSize dimension;
@property (nonatomic, assign) NSUInteger frameRate;
@property (nonatomic, assign) NSUInteger bitrate;
@property (nonatomic, assign) AgoraRteVideoOutputOrientationMode orientationMode;
@property (nonatomic, assign) AgoraRteDegradationPreference degradationPreference;
@property (nonatomic, assign) BOOL isMirror;

- (instancetype)initWithDimension:(CGSize)dimension
                        frameRate:(NSUInteger)frameRate
                          bitrate:(NSUInteger)bitrate
                         isMirror:(BOOL)isMirror
                  orientationMode:(AgoraRteVideoOutputOrientationMode)orientationMode
            degradationPreference:(AgoraRteDegradationPreference)degradationPreference;
@end

__attribute__((visibility("default")))
@interface AgoraRteDualVideoStreamConfig : AgoraRteObject
@property (nonatomic, strong) AgoraRteVideoEncoderConfig *highVideoEncoderConfig;
@property (nonatomic, strong) AgoraRteVideoEncoderConfig *lowVideoEncoderConfig;
@property (nonatomic, assign) BOOL enableDualStreamMode;

- (instancetype)initWithHighVideoEncoderConfig:(AgoraRteVideoEncoderConfig *)highVideoEncoderConfig
                         lowVideoEncoderConfig:(AgoraRteVideoEncoderConfig *)lowVideoEncoderConfig
                          enableDualStreamMode:(BOOL)enableDualStreamMode;
@end

__attribute__((visibility("default")))
@interface AgoraRteCameraCaptureParams : AgoraRteObject
@property (nonatomic, assign) CGSize dimension;
@property (nonatomic, assign) NSUInteger frameRate;
@property (nonatomic, assign) BOOL isMirror;

- (instancetype)initWithDimension:(CGSize)dimension
                        frameRate:(NSUInteger)frameRate
                         isMirror:(BOOL)isMirror;
@end

__attribute__((visibility("default")))
@interface AgoraRteScreenCaptureParams : AgoraRteObject
@property (nonatomic, assign) CGSize dimension;
@property (nonatomic, assign) NSUInteger frameRate;
@property (nonatomic, assign) NSUInteger bitrate;
@property (nonatomic, assign) BOOL hasAudio;

- (instancetype)initWithDimension:(CGSize)dimension
                        frameRate:(NSUInteger)frameRate
                          bitrate:(NSUInteger)bitrate
                         hasAudio:(BOOL)hasAudio;
@end

__attribute__((visibility("default")))
@interface AgoraRteBeautyOptions : AgoraRteObject
@property (nonatomic, assign) AgoraRteLighteningContrastLevel lighteningContrastLevel;
@property (nonatomic, assign) double lighteningLevel;
@property (nonatomic, assign) double smoothnessLevel;
@property (nonatomic, assign) double sharpnessLevel;
@property (nonatomic, assign) double rednessLevel;
@end

__attribute__((visibility("default")))
@interface AgoraRteVirtualBackgroundOptions : AgoraRteObject
@property (nonatomic, assign) AgoraRteVirtualBackgroundSourceType type;
@property (nonatomic, copy) NSString *source;
@property (nonatomic, assign) NSUInteger color;
@end

__attribute__((visibility("default")))
@interface AgoraRteAudioConfig : AgoraRteObject
@property (nonatomic, assign) AgoraRteAudioProfile profile;
@property (nonatomic, assign) AgoraRteAudioScenario scenario;

- (instancetype)initWithProfile:(AgoraRteAudioProfile)profile
                       scenario:(AgoraRteAudioScenario)scenario;
@end

__attribute__((visibility("default")))
@interface AgoraRteAudioRawDataConfig : AgoraRteObject
@property (nonatomic, assign) UInt64 sampleRate;
@property (nonatomic, assign) UInt64 samplesPerChannel;
@property (nonatomic, assign) UInt8 channels;
@property (nonatomic, assign) AgoraRteMediaRawDataOperationMode mode;
@end

__attribute__((visibility("default")))
@interface AgoraRteVideoRenderConfig : AgoraRteObject
@property (nonatomic, assign) AgoraRteVideoRenderMode renderMode;
@property (nonatomic, assign) BOOL isMirror;

- (instancetype)initWithRenderMode:(AgoraRteVideoRenderMode)renderMode;
@end

#pragma mark - Input - Media encryption
__attribute__((visibility("default")))
@interface  AgoraRteStreamEncryptionConfig: AgoraRteObject
@property (nonatomic, copy) NSString *encryptionKey;
@property (nonatomic, assign) NSInteger encryptionMode;

- (instancetype)initWithEncryptionKey:(NSString *)encryptionKey
                       encryptionMode:(NSInteger)encryptionMode;
@end

#pragma mark - Output
__attribute__((visibility("default")))
@interface AgoraRteMessage : AgoraRteObject
@property (nonatomic, strong) NSDictionary<NSString *, id> *payload;
@property (nonatomic, copy) NSString *cmd;
@property (nonatomic, assign) UInt64 timestamp;
@property (nonatomic, copy) NSString *senderId;
@end

#pragma mark - Output - Scene
__attribute__((visibility("default")))
@interface AgoraRteSceneInfo : AgoraRteObject
@property (nonatomic, copy) NSString *sceneId;
@property (nonatomic, copy) NSString *sceneName;
@property (nonatomic, assign) NSInteger createTime;
@end

__attribute__((visibility("default")))
@interface AgoraRteScenePropertiesUpdatedEvent : AgoraRteObject
@property (nonatomic, strong) NSDictionary<NSString *, id> *changedProperties;
@property (nonatomic, strong, nullable) NSDictionary<NSString *, id> *cause;
@property (nonatomic, strong, nullable) AgoraRteUserInfo *operatorUser;            
@end

__attribute__((visibility("default")))
@interface AgoraRteScenePropertiesDeletedEvent : AgoraRteObject
@property (nonatomic, strong) NSArray<NSString *> *changedKeyPaths;
@property (nonatomic, strong, nullable) NSDictionary<NSString *, id> *cause;
@property (nonatomic, strong, nullable) AgoraRteUserInfo *operatorUser;
@end

#pragma mark - Output - User
__attribute__((visibility("default")))
@interface AgoraRteUserInfo : AgoraRteObject <NSMutableCopying>
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *userRole;
@property (nonatomic, assign) AgoraRteRoomConnectorType connectorType;
@end

__attribute__((visibility("default")))
@interface AgoraRteUserEvent : AgoraRteObject
@property (nonatomic, strong) AgoraRteUserInfo *modifiedUser;
@property (nonatomic, strong, nullable) AgoraRteUserInfo *operatorUser;
@property (nonatomic, strong, nullable) NSDictionary<NSString *, id> *cause;
@end

@interface AgoraRteUserUpdatedEvent : AgoraRteObject
@property (nonatomic, strong) AgoraRteUserInfo *modifiedUser;
@property (nonatomic, strong, nullable) AgoraRteUserInfo *operatorUser;
@property (nonatomic, assign) AgoraRteUserUpdatedReason reason;
@end

__attribute__((visibility("default")))
@interface AgoraRteUserPropertiesUpdatedEvent : AgoraRteObject
@property (nonatomic, strong) NSDictionary<NSString *, id> *changedProperties;
@property (nonatomic, strong, nullable) NSDictionary<NSString *, id> *cause;
@property (nonatomic, strong) AgoraRteUserInfo *modifiedUser;
@property (nonatomic, strong, nullable) AgoraRteUserInfo *operatorUser;
@end

__attribute__((visibility("default")))
@interface AgoraRteUserPropertiesDeletedEvent : AgoraRteObject
@property (nonatomic, strong) NSArray<NSString *> *changedKeyPaths;
@property (nonatomic, strong, nullable) NSDictionary<NSString *, id> *cause;
@property (nonatomic, strong) AgoraRteUserInfo *modifiedUser;
@property (nonatomic, strong, nullable) AgoraRteUserInfo *operatorUser;
@end

#pragma mark - Output - Stream
__attribute__((visibility("default")))
@interface AgoraRteStreamInfo : AgoraRteObject <NSMutableCopying>
@property (nonatomic, copy) NSString *streamId;
@property (nonatomic, copy, nullable) NSString *streamName;
@property (nonatomic, strong) AgoraRteUserInfo *owner;
@property (nonatomic, assign) AgoraRteStreamType streamType;
@property (nonatomic, assign) AgoraRteVideoSourceType videoSourceType;
@property (nonatomic, assign) AgoraRteAudioSourceType audioSourceType;
@property (nonatomic, assign) AgoraRteMediaSourceState videoSourceState;
@property (nonatomic, assign) AgoraRteMediaSourceState audioSourceState;
@property (nonatomic, copy, nullable) NSString *videoSourceId;
@property (nonatomic, copy, nullable) NSString *audioSourceId;
@property (nonatomic, assign) AgoraRteRoomConnectorType connectorType;
@end

__attribute__((visibility("default")))
@interface AgoraRteStreamEvent : AgoraRteObject
@property (nonatomic, strong) AgoraRteStreamInfo *modifiedStream;
@property (nonatomic, strong, nullable) AgoraRteUserInfo *operatorUser;
@property (nonatomic, strong, nullable) NSDictionary<NSString *, id> *cause;
@end

#pragma mark - Output - Media
__attribute__((visibility("default")))
@interface AgoraRteSnapshotInfo : AgoraRteObject
@property (nonatomic, strong) NSString *streamId;
@property (nonatomic, strong) NSString *filePath;
@property (nonatomic, assign) UInt16 width;
@property (nonatomic, assign) UInt16 height;
@end

__attribute__((visibility("default")))
@interface AgoraRteAudioRawData : AgoraRteObject
@property (nonatomic, assign) UInt64 sampleRate;
@property (nonatomic, assign) UInt64 samplesPerChannel;
@property (nonatomic, assign) UInt8 channels;
@property (nonatomic, assign) UInt8 bytesPerSample;
@property (nonatomic, assign) UInt64 timestamp;
@property (nonatomic, strong) NSData* buffer;
@end

__attribute__((visibility("default")))
@interface AgoraRteDeviceInfo : AgoraRteObject
@property (nonatomic, copy) NSString *deviceName;
@property (nonatomic, copy) NSString *deviceId;
@end

#pragma mark - Output - Stats
__attribute__((visibility("default")))
@interface AgoraRteNetworkQualityEvent : AgoraRteObject
@property (nonatomic, assign) AgoraRteNetworkQuality txQuality;
@property (nonatomic, assign) AgoraRteNetworkQuality rxQuality;
@end

__attribute__((visibility("default")))
@interface AgoraRtePerformanceInfo : AgoraRteObject
/** Application CPU usage (%).
 */
@property (nonatomic, assign) double cpuAppUsage;
/** System CPU usage (%).
 */
@property (nonatomic, assign) double cpuTotalUsage;
/** The memory usage ratio of the app (%).
 **Note** This value is for reference only. Due to system limitations, you may not get the value of this member.
 */
@property (nonatomic, assign) double memoryAppUsageRatio;
/** The memory usage ratio of the system (%).
 **Note** This value is for reference only. Due to system limitations, you may not get the value of this member.
 */
@property (nonatomic, assign) double memoryTotalUsageRatio;
/** The memory usage of the app (KB).
 **Note** This value is for reference only. Due to system limitations, you may not get the value of this member.
 */
@property (nonatomic, assign) NSInteger memoryAppUsageInKbytes;
@end

__attribute__((visibility("default")))
@interface AgoraRteLocalAudioStats : AgoraRteObject
@property (nonatomic, assign) NSUInteger numChannels;
@property (nonatomic, assign) NSUInteger sentSampleRate;
@property (nonatomic, assign) NSUInteger sentBitrate;
@end

__attribute__((visibility("default")))
@interface AgoraRteLocalVideoStats : AgoraRteObject
@property (nonatomic, assign) NSUInteger sentBitrate;
@property (nonatomic, assign) NSUInteger sentFrameRate;
@property (nonatomic, assign) NSUInteger targetBitrate;
@property (nonatomic, assign) NSUInteger encodedFrameWidth;
@property (nonatomic, assign) NSUInteger encodedFrameHeight;
@property (nonatomic, assign) NSUInteger encodedFrameCount;
@property (nonatomic, assign) NSUInteger codecType;
@end

__attribute__((visibility("default")))
@interface AgoraRteRemoteAudioStats : AgoraRteObject
@property (nonatomic, assign) NSUInteger quality;
@property (nonatomic, assign) NSUInteger networkTransportDelay;
@property (nonatomic, assign) NSUInteger audioLossRate;
@property (nonatomic, assign) NSUInteger numChannels;
@property (nonatomic, assign) NSUInteger jitterBufferDelay;
@property (nonatomic, assign) NSUInteger receivedBitrate;
@property (nonatomic, assign) NSUInteger receivedSampleRate;
@property (nonatomic, assign) NSUInteger totalFrozenTime;
@property (nonatomic, assign) NSUInteger frozenRate;
@end

__attribute__((visibility("default")))
@interface AgoraRteRemoteVideoStats : AgoraRteObject
@property (nonatomic, assign) NSUInteger delay;
@property (nonatomic, assign) NSUInteger width;
@property (nonatomic, assign) NSUInteger height;
@property (nonatomic, assign) NSUInteger receivedBitrate;
@property (nonatomic, assign) NSUInteger receivedFrameRate;
@property (nonatomic, assign) NSUInteger rxStreamType;
@end

__attribute__((visibility("default")))
@interface AgoraRteNetworkStats: AgoraRteObject
/** Call duration (s), represented by an aggregate value.
 */
@property (nonatomic, assign) NSInteger duration;
/** Total number of bytes transmitted, represented by an aggregate value.
 */
@property (nonatomic, assign) NSInteger txBytes;
/** Total number of bytes received, represented by an aggregate value.
 */
@property (nonatomic, assign) NSInteger rxBytes;
/** Total number of audio bytes sent (bytes), represented by an aggregate value.
 */
@property (nonatomic, assign) NSInteger txAudioBytes;
/** Total number of video bytes sent (bytes), represented by an aggregate value.
 */
@property (nonatomic, assign) NSInteger txVideoBytes;
/** Total number of audio bytes received (bytes), represented by an aggregate value.
 */
@property (nonatomic, assign) NSInteger rxAudioBytes;
/** Total number of video bytes received (bytes), represented by an aggregate value.
 */
@property (nonatomic, assign) NSInteger rxVideoBytes;
/** Total packet transmission bitrate (Kbps), represented by an instantaneous value.
 */
@property (nonatomic, assign) NSInteger txKBitrate;
/** Total receive bitrate (Kbps), represented by an instantaneous value.
 */
@property (nonatomic, assign) NSInteger rxKBitrate;
/** Audio packet transmission bitrate (Kbps), represented by an instantaneous value.
 */
@property (nonatomic, assign) NSInteger txAudioKBitrate;
/** Audio receive bitrate (Kbps), represented by an instantaneous value.
 */
@property (nonatomic, assign) NSInteger rxAudioKBitrate;
/** Video transmission bitrate (Kbps), represented by an instantaneous value.
 */
@property (nonatomic, assign) NSInteger txVideoKBitrate;
/** Video receive bitrate (Kbps), represented by an instantaneous value.
 */
@property (nonatomic, assign) NSInteger rxVideoKBitrate;
/** Client-server latency (ms)
 */
@property (nonatomic, assign) NSInteger lastmileDelay;
/** The packet loss rate (%) from the local client to Agora's edge server, before using the anti-packet-loss method.
 */
@property (nonatomic, assign) NSInteger txPacketLossRate;
/** The packet loss rate (%) from Agora's edge server to the local client, before using the anti-packet-loss method.
 */
@property (nonatomic, assign) NSInteger rxPacketLossRate;
/** The round-trip time delay from the client to the local router.
 */
@property (nonatomic, assign) NSInteger gatewayRtt;
@end

#pragma mark - Output - Lastmile
__attribute__((visibility("default")))
@interface AgoraRteLastmileProbeConfig : AgoraRteObject
/** Sets whether or not to test the uplink network. Some users, for example, the audience in the interactive live streaming channel, do not need such a test.

- NO: disables the test.
- YES: enables the test.
*/
@property (assign, nonatomic) BOOL probeUplink;
/** Sets whether or not to test the downlink network.

- NO: disables the test.
- YES: enables the test.
*/
@property (assign, nonatomic) BOOL probeDownlink;
/** The expected maximum sending bitrate (bps) of the local user.

The value ranges between 100000 and 5000000. We recommend setting this parameter according to the bitrate value set by [setVideoEncoderConfiguration]([AgoraRtcEngineKit setVideoEncoderConfiguration:]). */
@property (assign, nonatomic) NSUInteger expectedUplinkBitrate;
/** The expected maximum receiving bitrate (bps) of the local user.

The value ranges between 100000 and 5000000.
*/
@property (assign, nonatomic) NSUInteger expectedDownlinkBitrate;
@end

NS_ASSUME_NONNULL_END
