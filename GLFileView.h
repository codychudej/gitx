//
//  GLFileView.h
//  GitX
//
//  Created by German Laullon on 14/09/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PBWebController.h"
#import "MGScopeBarDelegateProtocol.h"
#import "PBGitCommit.h"
#import "PBGitHistoryController.h"
#import "PBRefContextDelegate.h"

@class PBGitGradientBarView;

@interface GLFileView : PBWebController <MGScopeBarDelegate> {
	IBOutlet PBGitHistoryController* historyController;
	IBOutlet MGScopeBar *typeBar;
	NSMutableArray *groups;
	NSString *logFormat;
	NSString *diffType;
	IBOutlet NSView *accessoryView;
	IBOutlet NSSplitView *fileListSplitView;
}

- (void)showFile;
- (void)didLoad;
- (NSString *)parseBlame:(NSString *)txt;
+ (NSString *)parseHTML:(NSString *)txt;
+ (NSString *)parseDiff:(NSString *)txt;
+ (NSString *)parseDiffTree:(NSString *)txt withStats:(NSMutableDictionary *)stats;
+(BOOL)isStartDiff:(NSString *)line;
+(BOOL)isStartBlock:(NSString *)line;

@property(retain) NSMutableArray *groups;
@property(retain) NSString *logFormat;

@end
