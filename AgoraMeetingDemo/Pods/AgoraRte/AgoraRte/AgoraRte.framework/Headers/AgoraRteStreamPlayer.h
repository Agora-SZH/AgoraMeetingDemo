//
//  AgoraRteStreamPlayer.h
//  AgoraRte
//
//  Created by Cavan on 2023/11/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AgoraRteStreamPlayer;
@protocol AgoraRteStreamPlayerDelegate <NSObject>

@end

@protocol AgoraRteStreamPlayer <NSObject>
@property (nonatomic, weak) NSObject<AgoraRteStreamPlayerDelegate> *delegate;

// Subscribe
- (AgoraRteError * _Nullable)subscribeRemoteVideoStream:(NSString *)streamId
                                                   type:(AgoraRteVideoStreamType)type;

- (AgoraRteError * _Nullable)unsubscribeRemoteVideoStream:(NSString *)streamId;

// Video render
- (AgoraRteError * _Nullable)startRenderRemoteVideoStream:(NSString *)streamId
                                                     view:(VIEW_CLASS *)view
                                                   config:(AgoraRteVideoRenderConfig *)config;

- (AgoraRteError * _Nullable)stopRenderRemoteVideoStream:(NSString *)streamId
                                                    view:(VIEW_CLASS *)view;

// Audio play
- (AgoraRteError * _Nullable)startPlayRemoteAudioStream:(NSString *)streamId;

- (AgoraRteError * _Nullable)stopPlayRemoteAudioStream:(NSString *)streamId;

- (AgoraRteError * _Nullable)updateRemoteAudioStream:(NSString *)streamId
                                              volume:(NSUInteger)volume;

// Snapshot
- (void)takeSnapshot:(NSString *)streamId
            filePath:(NSString *)filePath
             success:(AgoraRteSnapshotCompletion _Nullable)success
             failure:(AgoraRteErrorCompletion _Nullable)failure;

// Raw data
- (AgoraRteError * _Nullable)setAudioRawDataConfig:(AgoraRteAudioRawDataConfig *)config
                                          position:(AgoraRteAudioRawDataOutputPosition)position;

- (AgoraRteError * _Nullable)addAudioRawDataObserver:(id<AgoraRteAudioRawOutputDataObserver>)observer
                                            position:(AgoraRteAudioRawDataOutputPosition)position;

- (AgoraRteError * _Nullable)removeAudioRawDataObserver:(id<AgoraRteAudioRawOutputDataObserver>)observer
                                               position:(AgoraRteAudioRawDataOutputPosition)position;
@end

NS_ASSUME_NONNULL_END
