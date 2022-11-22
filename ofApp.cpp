#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofNoFill();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofColor color;
	for (float base_deg = 0; base_deg < 360; base_deg += 1) {

		vector<glm::vec2> vertices;
		auto base_radius = ofRandom(720);
		auto speed = ofRandom(3, 5);
		auto deg_speed = ofRandom(2, 6);

		for (int i = 0; i < ofMap(deg_speed, 2, 6, 30, 10); i++) {

			auto deg = base_deg + (ofGetFrameNum() + i) * deg_speed;
			auto radius = 800 - (int)(base_radius + (ofGetFrameNum() + i) * speed) % 800;
			if (radius < 100) { radius = 100; }
			auto vertex = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

			if (i > 0 && glm::distance(vertex, vertices.back()) > 100) {

				continue;
			}
			vertices.push_back(vertex);
		}
		
		color.setHsb(ofRandom(255), 80, 255);
		ofSetColor(color);

		ofBeginShape();
		ofVertices(vertices);
		ofEndShape();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}