#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include "physics/PhysicsMonitor.hpp"
#include "ui/PhysicsOverlay.hpp"
#include "hooks/PlayLayerHook.hpp"

$on_mod(Loaded) {
	PhysicsMonitor::getInstance();
}