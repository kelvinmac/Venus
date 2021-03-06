//
// Created by Kelvin Macartney on 18/03/2020.
//

#include "system.h"

Venus::Core::System::System() = default;

void Venus::Core::System::ignition() {
    using namespace Venus;

    this->_logger = Factories::Logging::LoggingFactory::CreateLogger(Venus::Factories::Logging::LoggerType::DailyFile,
                                                                     "Engine::System", "Venus::System.log");

    this->_logger->info("System ignited");
}

void Venus::Core::System::shutdown() {
    Module::shutdown();

    this->_logger->info("System shutting down");
}

void Venus::Core::System::terminate() {
    auto logger = spdlog::get("Engine::System");

    if (logger != nullptr) logger->error("Termination requested");

    // Flush all logger
    spdlog::apply_all([](std::shared_ptr<spdlog::logger> l) {
        l->flush();
    });

    spdlog::shutdown();
    exit(0);
}

