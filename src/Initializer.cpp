#include "Initializer.h"

Initializer::Initializer(): initialized(false), freed(false) {
}

void Initializer::initialize() {
    if (!initialized) {
        setup();
        initialized = true;
    }
}

void Initializer::shutdown() {
    if (!freed) {
        teardown();
        freed = true;
    }
}

bool Initializer::is_initialized() const {
    return (initialized);
};

bool Initializer::is_freed() const {
    return (freed);
};

void Startup::add_initializer(std::shared_ptr<Initializer> initializer) {
    initializers.push_back(std::move(initializer));
}

void Startup::init() {
    for (const auto& initializer : initializers) {
        if (!initializer->is_initialized()) {
            initializer->initialize();
        }
    }
}

void Startup::shutdown() {
    for (auto initializer = initializers.rbegin(); initializer != initializers.rend(); ++initializer) {
        if ((*initializer)->is_initialized() && !(*initializer)->is_freed()) {
            (*initializer)->shutdown();
        }
    }
}