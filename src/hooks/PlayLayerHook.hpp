#pragma once

#include <Geode/Geode.hpp>
#include "physics/PhysicsMonitor.hpp"
#include "ui/PhysicsOverlay.hpp"

using namespace geode::prelude;

#include <Geode/modify/PlayLayer.hpp>
class $modify(PlayLayerHook, PlayLayer) {
public:
	bool init(GJGameLevel* p0, bool p1, bool p2) {
		if (!PlayLayer::init(p0, p1, p2)) return false;

		PhysicsMonitor::getInstance()->reset();

		auto timerNode = PhysicsMonitor::TimerNode::create(PhysicsMonitor::getInstance());
		if (timerNode) {
			this->addChild(timerNode, -100);
		}

		g_physicsOverlay = PhysicsOverlay::create();
		if (g_physicsOverlay) {
			this->addChild(g_physicsOverlay, 1000);
			g_physicsOverlay->setPosition(10, 10);
		} else {
			log::error("Failed to create physics overlay!");
		}

		return true;
	}
};
