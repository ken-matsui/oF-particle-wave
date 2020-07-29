#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面設定
    ofSetFrameRate(60);
    ofBackground(0); // 背景色の設定
    
    // メッシュを点で描画
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(2.0);

    // パーティクルの初期化
    for (int i = 0; i < NUM; i++) {
        particlePos[i] = ofVec2f(ofRandom(ofGetWidth()), ofGetHeight()/2);
        particleFor[i] = ofVec2f(1.0, 1.0);
        particleNoise[i] = ofVec2f(ofRandom(10), ofRandom(10));
        
        red[i] = ofRandom(255);
        green[i] = ofRandom(255);
        blue[i] = ofRandom(255);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // ノイズの変更
    for (int i = 0; i < NUM; i++) {
        particleNoise[i].x += 0.01;
        particleNoise[i].y += 0.01;
    }
    
    // ノイズの発生
    for (int i = 0; i < NUM; i++) {
        particleFor[i] *= ofSignedNoise(particleNoise[i].x, particleNoise[i].y);

        
        if(count % 2 == 0){
            particlePos[i].y += particleFor[i].y;
        }
        else{
            particlePos[i].y -= particleFor[i].y;
        }
        
        // 力のリセット
        particleFor[i] = ofVec2f(1.0, 1.0);
        
        count++;
    }
    
    for (int i = 0; i < NUM; i++) {
        red[i] += 0.01;
        green[i] += 0.01;
        blue[i] += 0.01;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // メッシュの描画
    mesh.clear();
    for (int i = 0; i < NUM; i++) {
        ofSetColor(ofNoise(red[i]) * 255, ofNoise(green[i]) * 255, ofNoise(blue[i]) * 255);
        mesh.addVertex(ofVec3f(particlePos[i].x, particlePos[i].y, 0));
    }
    mesh.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
