//
//  AgoraRteMonitor.h
//  AgoraRte
//
//  Created by Cavan on 2023/7/24.
//

#import <Foundation/Foundation.h>
#import <AgoraFoundation/AgoraFoundation-Swift.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AgoraRteMonitor;
@protocol AgoraRteMonitorObserver <NSObject>
@optional
- (void)onPerformanceUpdated:(AgoraRtePerformanceInfo *)info;
- (void)onMediaErrorOccurred:(NSInteger)code;
@end

__attribute__((visibility("default")))
@protocol AgoraRteMonitor <NSObject>
@property (nonatomic, weak) id<AgoraRteMonitorObserver> delegate;

- (void)uploadLogWithTags:(NSDictionary<NSString *, id> *)tags
                  success:(AgoraRteStringCompletion _Nullable)success
                  failure:(AgoraRteErrorCompletion _Nullable)failure;

- (void)addObserver:(id<AgoraRteMonitorObserver>)observer;
- (void)removeObserver:(id<AgoraRteMonitorObserver>)observer;
@end

NS_ASSUME_NONNULL_END
