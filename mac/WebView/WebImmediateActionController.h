/*
 * Copyright (C) 2014 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#if PLATFORM(MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 101000

#import "WebUIDelegatePrivate.h"
#import <WebCore/HitTestResult.h>
#import <WebCore/NSImmediateActionGestureRecognizerSPI.h>
#import <wtf/RetainPtr.h>

@class DDActionContext;
@class WebView;

namespace WebCore {
class Range;
class TextIndicator;
}

@interface WebImmediateActionController : NSObject <NSImmediateActionGestureRecognizerDelegate> {
@private
    WebView *_webView;
    WebImmediateActionType _type;
    WebCore::HitTestResult _hitTestResult;
    NSImmediateActionGestureRecognizer *_immediateActionRecognizer;

    RetainPtr<DDActionContext> _currentActionContext;
    RefPtr<WebCore::Range> _currentDetectedDataRange;
    RefPtr<WebCore::TextIndicator> _currentDetectedDataTextIndicator;
    BOOL _isShowingTextIndicator;
    BOOL _hasActivatedActionContext;
}

- (instancetype)initWithWebView:(WebView *)webView recognizer:(NSImmediateActionGestureRecognizer *)immediateActionRecognizer;
- (void)webViewClosed;

- (void)webView:(WebView *)webView willHandleMouseDown:(NSEvent *)event;

@end

#endif // PLATFORM(MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 101000