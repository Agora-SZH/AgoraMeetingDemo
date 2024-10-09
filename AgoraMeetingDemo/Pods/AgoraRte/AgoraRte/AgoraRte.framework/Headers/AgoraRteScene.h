//
//  AgoraRteScene.h
//  AgoraRte
//
//  Created by Cavan on 2023/4/21.
//

#import <Foundation/Foundation.h>
#import "AgoraRteStreamPlayer.h"
#import "AgoraRteLocalUser.h"
#import "AgoraRteObjects.h"
#import "AgoraRteEnums.h"

NS_ASSUME_NONNULL_BEGIN
typedef void(^AgoraRteJoinCompletion) (NSObject<AgoraRteLocalUser> * user,
                                       NSObject<AgoraRteStreamPlayer> * streamPlayer);

@protocol AgoraRteScene;
@protocol AgoraRteSceneObserver <NSObject>
@optional
- (void)onSceneMessageReceivedWithSceneId:(NSString *)sceneId
                                  message:(AgoraRteMessage *)message;

- (void)onJoinSceneSuccessWithSceneId:(NSString *)sceneId
                     rtcChannelClient:(NSObject *)rtcChannelClient
                            localUser:(NSObject<AgoraRteLocalUser> *)localUser
                         streamPlayer:(NSObject<AgoraRteStreamPlayer> *)streamPlayer;

- (void)onJoinSceneFailureWithSceneId:(NSString *)sceneId
                                error:(AgoraRteError *)error;

// Properties
- (void)onScenePropertiesUpdatedWithSceneId:(NSString *)sceneId
                                      event:(AgoraRteScenePropertiesUpdatedEvent *)event;

- (void)onScenePropertiesDeletedWithSceneId:(NSString *)sceneId
                                      event:(AgoraRteScenePropertiesDeletedEvent *)event;

- (void)onUserPropertiesUpdatedWithSceneId:(NSString *)sceneId
                                     event:(AgoraRteUserPropertiesUpdatedEvent *)event;

- (void)onUserPropertiesDeletedWithSceneId:(NSString *)sceneId
                                     event:(AgoraRteUserPropertiesDeletedEvent *)event;

// User
- (void)onRemoteUsersJoinedWithSceneId:(NSString *)sceneId
                                events:(NSArray<AgoraRteUserEvent *> *)events;

- (void)onRemoteUsersLeftWithSceneId:(NSString *)sceneId
                              events:(NSArray<AgoraRteUserEvent *> *)events;

- (void)onUserUpdatedWithSceneId:(NSString *)sceneId
                           event:(AgoraRteUserUpdatedEvent *)event;

- (void)onAllUserCountUpdatedWithSceneId:(NSString *)sceneId
                                   count:(UInt32)count;

// Streams
- (void)onStreamsAddedWithSceneId:(NSString *)sceneId
                           events:(NSArray<AgoraRteStreamEvent *> *)events;

- (void)onStreamsUpdatedWithSceneId:(NSString *)sceneId
                             events:(NSArray<AgoraRteStreamEvent *> *)events;

- (void)onStreamsRemovedWithSceneId:(NSString *)sceneId
                             events:(NSArray<AgoraRteStreamEvent *> *)events;

- (void)onStreamVolumeIndicationUpdatedWithSceneId:(NSString *)sceneId
                                          streamId:(NSString *)streamId
                                            volume:(NSUInteger)volume;

- (void)onLocalStreamVideoStatsUpdatedWithSceneId:(NSString *)sceneId
                                         streamId:(NSString *)streamId
                                            stats:(AgoraRteLocalVideoStats *)stats;

- (void)onLocalStreamAudioStatsUpdatedWithSceneId:(NSString *)sceneId
                                         streamId:(NSString *)streamId
                                            stats:(AgoraRteLocalAudioStats *)stats;


- (void)onRemoteStreamVideoStatsUpdatedWithSceneId:(NSString *)sceneId
                                         streamId:(NSString *)streamId
                                            stats:(AgoraRteRemoteVideoStats *)stats;

- (void)onRemoteStreamAudioStatsUpdatedWithSceneId:(NSString *)sceneId
                                          streamId:(NSString *)streamId
                                             stats:(AgoraRteRemoteAudioStats *)stats;

- (void)onFirstRemoteVideoFrameRenderedWithSceneId:(NSString *)sceneId
                                          streamId:(NSString *)streamId
                                        dimensions:(CGSize)dimensions;

// Network
- (void)onNetworkQualityUpdatedWithSceneId:(NSString *)sceneId
                                     event:(AgoraRteNetworkQualityEvent *)event;
                                  
- (void)onNetworkStatsUpdatedWithSceneId:(NSString *)sceneId
                                   stats:(AgoraRteNetworkStats *)stats;
@end

@protocol AgoraRteScene <NSObject>
- (void)joinWithOptions:(AgoraRteSceneJoinOptions *)options
                success:(AgoraRteJoinCompletion)success
                failure:(AgoraRteErrorCompletion _Nullable)failure;

- (void)joinWithSnapshotOptions:(AgoraRteSceneJoinSnapshotOptions *)options
                        success:(AgoraRteJoinCompletion)success
                        failure:(AgoraRteErrorCompletion _Nullable)failure;

- (void)leave;

- (AgoraRteSceneInfo * _Nullable)getSceneInfo;
- (NSObject<AgoraRteLocalUser> * _Nullable)getLocalUser;
- (NSObject<AgoraRteStreamPlayer> * _Nullable)getStreamPlayer;

// User
- (NSDictionary<NSString *, AgoraRteUserInfo *> *)getUsers; // Key: userId
- (AgoraRteUserInfo * _Nullable)getUser:(NSString *)userId;
- (NSArray<AgoraRteUserInfo *> *)getUserList;
- (UInt32)getAllUserCount;
- (void)fetchUserListWithParams:(AgoraRteUserPageParams *)params
                        success:(AgoraRteUserPageCompletion)success
                        failure:(AgoraRteErrorCompletion _Nullable)failure;

// Stream
- (NSDictionary<NSString *, NSArray<AgoraRteStreamInfo *> *> * _Nullable)getStreams;  // Key: userId
- (NSArray<AgoraRteStreamInfo *> * _Nullable)getStreamsByUserId:(NSString *)userId;
- (NSArray<AgoraRteStreamInfo *> * _Nullable)getStreamList;
- (AgoraRteStreamInfo * _Nullable)getStreamByStreamId:(NSString *)streamId;

// Scene properties
- (NSDictionary<NSString *, id> * _Nullable)getSceneProperties;
- (id _Nullable)getScenePropertiesByKeyPath:(NSString *)keyPath;

// User properties
- (NSDictionary<NSString *, id> * _Nullable)getUserProperties;
- (NSDictionary<NSString *, id> * _Nullable)getUserPropertiesByUserId:(NSString * _Nonnull)userId;
- (id _Nullable)getUserPropertiesByKeyPath:(NSString * _Nonnull)keyPath
                                    userId:(NSString * _Nonnull)userId;

- (NSString *)getCallId;
- (NSString *)getSessionId;

/// Represents the time in millisecond
- (UInt64)getSyncTimestamp;

- (void)addObserver:(id<AgoraRteSceneObserver>)observer;
- (void)removeObserver:(id<AgoraRteSceneObserver>)observer;

#pragma mark Unavailable Initializers
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
