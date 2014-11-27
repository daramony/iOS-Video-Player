//
//  HKVideoPlayerCoreDelegate.h
//  iOS Video Player
//
//  Created by Hai Kieu on 11/22/14.
//  Copyright (c) 2014 haikieu2907@gmail.com. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Implemented by HKVideoPlayerThemeView abstract class
 Flow: CoreView ->[invoke]-> ViewController ->[invoke]-> ThemeView
*/
@protocol HKVideoPlayerThemeViewOverrideDelegate <NSObject>

-(BOOL) themeViewAllowDraggableAtPosition:(CGPoint)postion;
-(BOOL) themeViewAllowResizeWithFrame:(CGRect)frame;

-(BOOL) themeViewNeedClipsToBounds;

-(BOOL) themeViewShouldSupportIpadnIphone;
-(BOOL) themeViewShouldSupportIpad;
-(BOOL) themeViewShouldSupportIphone;

@end

/**
 Implemented by HKVideoPlayerThemeView abstract class as well as HKVideoPlayerViewController
 Flow: CoreView ->[invoke]-> ViewController ->[invoke]-> ThemeView
 */
@protocol HKVideoPlayerCoreEventDelegate <NSObject>

-(UIEdgeInsets)playerGetConfigInsets;

@end

/**
 Implemented by HKVideoPlayerThemeView abstract class
 Flow: ViewController ->[invoke]-> ThemeView
*/
@protocol HKVideoPlayerPreEventDelegate <HKVideoPlayerCoreEventDelegate>

-(void) playerWillLoad;
-(void) playerWillPlay;
-(void) playerWillStop;
-(void) playerWillPause;
-(void) playerWillEnterFullscreen;
-(void) playerWillExitFullscreen;
-(void) playerWillRewind:(float)speed;
-(void) playerWillFastforward:(float)speed;
-(void) playerWillUpdateTime:(float)second;
-(void) playerWillCloseView;

-(void) playerWillResizeWithFrame:(CGRect)frame;

@end

/**
  Implemented by HKVideoPlayerThemeView abstract class as well as HKVideoPlayerViewController
  Flow: CoreView ->[invoke]-> ViewController ->[invoke]-> ThemeView
*/
@protocol HKVideoPlayerPostEventDelegate <HKVideoPlayerCoreEventDelegate>

-(void) playerDidRenderView;
-(void) playerDidLoad;
-(void) playerDidFailure;
-(void) playerDidReady;
-(void) playerDidPlay;
-(void) playerDidStop;
-(void) playerDidPause;
-(void) playerDidEnterFullscreen;
-(void) playerDidExitFullscreen;
-(void) playerDidRewind:(float)speed;
-(void) playerDidFastforward:(float)speed;
-(void) playerDidUpdateTime:(float)second DEPRECATED_MSG_ATTRIBUTE("Deprecated now");

-(void) playerDidUpdateCurrentTime:(float)currentTime remainTime:(float)remainTime durationTime:(float)durationTime;
-(void) playerDidCloseView;
-(void) playerDidResizeWithFrame:(CGRect)frame;

@end