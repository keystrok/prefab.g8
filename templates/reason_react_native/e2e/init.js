const detox = require('detox');
const config = require('../package.json').detox;
const adapter = require('detox/runners/jest/adapter');
const specReporter = require('detox/runners/jest/specReporter');

// Set the default timeout
// jest.setTimeout(25000);
// jasmine.getEnv().addReporter(adapter);

// This takes care of generating status logs on a per-spec basis. By default, jest only reports at file-level.
// This is strictly optional.
// jasmine.getEnv().addReporter(specReporter);

beforeEach(async () => {
    await device.reloadReactNative();
});

beforeAll(async () => {
    await device.launchApp();
});
