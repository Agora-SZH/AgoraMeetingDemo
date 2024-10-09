//
//  AgoraRteMediaRawDataProtocols.h
//  AgoraRte
//
//  Created by Cavan on 2023/4/17.
//

#import <Foundation/Foundation.h>
#import "AgoraRteObjects.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AgoraRteAudioRawDataObserver <NSObject>

@end

@protocol AgoraRteRecordAudioRawDataObserver <AgoraRteAudioRawDataObserver>
- (void)onAudioRawDataRecord:(AgoraRteAudioRawData *)data;
@end

@protocol AgoraRteAudioRawOutputDataObserver <AgoraRteAudioRawDataObserver>
@optional
- (void)onAudioRawDataBeforeMixed:(AgoraRteAudioRawData *)data
                         streamId:(NSString *)streamId
                          sceneId:(NSString *)sceneId;

- (void)onAudioRawDataPlayback:(AgoraRteAudioRawData *)data;

- (void)onAudioRawDataMixed:(AgoraRteAudioRawData *)data;
@end

NS_ASSUME_NONNULL_END

