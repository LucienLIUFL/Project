#include "AppDelegate.h"
#include "../View/HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "../View/GameMain.h"

USING_NS_CC;

AppDelegate::AppDelegate() {}

AppDelegate::~AppDelegate() {}

void AppDelegate::initGLContextAttrs() {
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
        glview = GLViewImpl::createWithRect("MyGame", cocos2d::Rect(0, 0, 320, 480));
        director->setOpenGLView(glview);
    }
    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

	director->getOpenGLView()->setDesignResolutionSize(640, 960, ResolutionPolicy::EXACT_FIT);

	// create a scene. it's an autorelease object
	Scene * scene = HelloWorld::createScene();
    director->runWithScene(scene);
    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
