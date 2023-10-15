//C:\\Windows\\Fonts\\Arial.ttf

//Chuyển đổi qua lại giữa các Release thì chỉ cần dùng Ctrl + Shift + X và cái Release kia phải làm ngược lại (Bằng cách cũng làm y như kia nhưng thay thành chữ "C")

//Bản Beta

//#include <SFML/Graphics.hpp>
//#include <windows.h>
//#include <pdh.h>
//#include <bits/stdc++.h>
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "CPU and RAM Monitor");
//    window.setFramerateLimit(60);
//
//    // Font for displaying text
//    sf::Font font;
//    font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf");
//
//    // Text to display FPS
//    sf::Text fpsText;
//    fpsText.setFont(font);
//    fpsText.setCharacterSize(20);
//    fpsText.setPosition(10, 10);
//
//    // Text to label CPU and RAM
//    sf::Text cpuLabel;
//    cpuLabel.setFont(font);
//    cpuLabel.setCharacterSize(20);
//    cpuLabel.setPosition(100, 500);
//    cpuLabel.setString("CPU");
//
//    sf::Text ramLabel;
//    ramLabel.setFont(font);
//    ramLabel.setCharacterSize(20);
//    ramLabel.setPosition(300, 500);
//    ramLabel.setString("RAM");
//
//    // Initialize Performance Data Helper
//    PDH_HQUERY hQuery;
//    PDH_HCOUNTER hCounterCPU;
//    PDH_HCOUNTER hCounterRAM;
//    PdhOpenQuery(NULL, 0, &hQuery);
//    PdhAddCounter(hQuery, "\\Processor(_Total)\\% Processor Time", 0, &hCounterCPU);
//    PdhAddCounter(hQuery, "\\Memory\\% Committed Bytes In Use", 0, &hCounterRAM);
//    PdhCollectQueryData(hQuery);
//
//    sf::Clock clock; // Create a clock to measure time
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//        }
//
//        // Get CPU usage
//        PdhCollectQueryData(hQuery);
//        PDH_FMT_COUNTERVALUE valueCPU;
//        PdhGetFormattedCounterValue(hCounterCPU, PDH_FMT_DOUBLE, NULL, &valueCPU);
//        double cpuUsage = valueCPU.doubleValue;
//
//        // Get RAM usage
//        PDH_FMT_COUNTERVALUE valueRAM;
//        PdhGetFormattedCounterValue(hCounterRAM, PDH_FMT_DOUBLE, NULL, &valueRAM);
//        double ramUsage = valueRAM.doubleValue;
//
//        // Display CPU and RAM usage
//        std::cout << "CPU: " << cpuUsage << "% | RAM: " << ramUsage << "%\r";
//
//        // Clear the window
//        window.clear();
//
//        // Draw CPU and RAM bars (you can customize this part)
//        sf::RectangleShape cpuBar(sf::Vector2f(100, -cpuUsage * 2));
//        sf::RectangleShape ramBar(sf::Vector2f(100, -ramUsage * 2));
//        cpuBar.setFillColor(sf::Color::Red);
//        ramBar.setFillColor(sf::Color::Blue);
//        cpuBar.setPosition(100, 500);
//        ramBar.setPosition(300, 500);
//        window.draw(cpuBar);
//        window.draw(ramBar);
//
//        // Draw labels and FPS
//        window.draw(cpuLabel);
//        window.draw(ramLabel);
//        window.draw(fpsText);
//
//        // Display the window
//        window.display();
//
//        // Update FPS text
//        fpsText.setString("FPS: " + std::to_string(1.0 / clock.restart().asSeconds()));
//    }
//
//    PdhCloseQuery(hQuery);
//
//    return 0;
//}
//
//
//


//Bản Release 1

//#include <SFML/Graphics.hpp>
//#include <windows.h>
//#include <iostream>
//#include <string>
//#include <iomanip>
//#include <pdh.h>
//#include <bits/stdc++.h>
//
//const int windowWidth = 800;
//const int windowHeight = 600;
//const int chartWidth = 600;
//const int chartHeight = 400;
//const int chartMargin = 10;
//const int refreshInterval = 1000; // 1 second
//
//void updateStats(float& cpuUsage, float& ramUsage, MEMORYSTATUSEX& memInfo) {
//    // Get CPU usage
//    // (Your CPU usage calculation code here)
//    FILETIME idleTime, kernelTime, userTime;
//    if (GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
//        ULONGLONG kernelTimeDelta = kernelTime.dwLowDateTime + ((ULONGLONG)kernelTime.dwHighDateTime << 32);
//        ULONGLONG userTimeDelta = userTime.dwLowDateTime + ((ULONGLONG)userTime.dwHighDateTime << 32);
//        ULONGLONG idleTimeDelta = idleTime.dwLowDateTime + ((ULONGLONG)idleTime.dwHighDateTime << 32);
//
//        static ULONGLONG prevIdleTime = 0, prevTotalTime = 0;
//        ULONGLONG idleTimeDeltaDiff = idleTimeDelta - prevIdleTime;
//        ULONGLONG totalTimeDelta = (kernelTimeDelta + userTimeDelta) - prevTotalTime;
//
//        if (totalTimeDelta > 0) {
//            cpuUsage = 100.0f * (1.0f - (static_cast<float>(idleTimeDeltaDiff) / totalTimeDelta));
//        }
//
//        prevIdleTime = idleTimeDelta;
//        prevTotalTime = kernelTimeDelta + userTimeDelta;
//    }
//
//
//
//    // Get RAM usage
//    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
//    GlobalMemoryStatusEx(&memInfo);
//    ramUsage = 100.0f * (1.0f - (static_cast<float>(memInfo.ullAvailPhys) / memInfo.ullTotalPhys));
//}
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Performance Monitor");
//    window.setFramerateLimit(NULL); // Limit frame rate
//
//    sf::Image icon;
//    if (icon.loadFromFile("icon.png")) {
//        // Set the window icon
//        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
//    } else {
//        // Handle the case where the icon couldn't be loaded
//        // Optionally, you can use a default icon or display an error message.
//    }
//
//    sf::Font font;
//    font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf");
//
//    sf::Text fpsText;
//    fpsText.setFont(font);
//    fpsText.setCharacterSize(20);
//    fpsText.setFillColor(sf::Color::White);
//    fpsText.setPosition(10,50); //Old Setting: windowWidth - 100, 10
//
//    sf::Text cpuText;
//    cpuText.setFont(font);
//    cpuText.setCharacterSize(20);
//    cpuText.setFillColor(sf::Color::Green);
//    cpuText.setPosition(10,10); //Old Setting: 10, windowHeight - chartHeight - chartMargin - 40
//
//    sf::Text ramText;
//    ramText.setFont(font);
//    ramText.setCharacterSize(20);
//    ramText.setFillColor(sf::Color::Red);
//    ramText.setPosition(10,30); //Old Setting: 10, windowHeight - chartHeight - chartMargin - 10
//
//    sf::RectangleShape cpuChart;
//    cpuChart.setSize(sf::Vector2f(chartWidth / 2, 0));
//    cpuChart.setFillColor(sf::Color::Green);
//    cpuChart.setPosition(10, windowHeight - chartMargin);
//
//    sf::RectangleShape ramChart;
//    ramChart.setSize(sf::Vector2f(chartWidth / 2, 0));
//    ramChart.setFillColor(sf::Color::Red);
//    ramChart.setPosition(10 + chartWidth / 2, windowHeight - chartMargin);
//
//    MEMORYSTATUSEX memInfo;
//    float cpuUsage = 0.0f;
//    float ramUsage = 0.0f;
//    int frameCount = 0;
//    sf::Clock clock;
//    sf::Clock fpsClock;
//    int frames = 0;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//        }
//
//        if (clock.getElapsedTime().asMilliseconds() >= refreshInterval) {
//            updateStats(cpuUsage, ramUsage, memInfo);
//
//            std::string cpuUsageStr = "CPU: " + std::to_string(std::round(cpuUsage)) + "%";
//            std::string ramUsageStr = "RAM: " + std::to_string(std::round(ramUsage)) + "%";
//
//            cpuText.setString(cpuUsageStr);
//            ramText.setString(ramUsageStr);
//
//            std::cout << "\r" << cpuUsageStr << " | " << ramUsageStr << std::flush;
//
//            float cpuHeight = chartHeight * (cpuUsage / 100.0f);
//            float ramHeight = chartHeight * (ramUsage / 100.0f);
//
//            cpuChart.setSize(sf::Vector2f(chartWidth / 2, -cpuHeight));
//            ramChart.setSize(sf::Vector2f(chartWidth / 2, -ramHeight));
//
//            frameCount++;
//            if (frameCount * (refreshInterval / 1000.0f) >= chartWidth) {
//                frameCount = chartWidth;
//            }
//
//            clock.restart();
//        }
//
//        frames++;
//        if (fpsClock.getElapsedTime().asSeconds() >= 1.0) {
//            int fps = frames;
//            frames = 0;
//            fpsText.setString("FPS: " + std::to_string(fps));
//            fpsClock.restart();
//        }
//
//        window.clear(sf::Color::Black);
//        window.draw(fpsText);
//        window.draw(cpuText);
//        window.draw(ramText);
//        window.draw(cpuChart);
//        window.draw(ramChart);
//        window.display();
//    }
//
//    return 0;
//}



//
//Release 2
//
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <bits/stdc++.h>

const int windowWidth = 800;
const int windowHeight = 600;
const int chartWidth = 300; // Adjust the width as desired
const int chartHeight = 400;
const int chartMargin = 10;
const int refreshInterval = 1000; // 1 second

void updateStats(float& cpuUsage, float& ramUsage, MEMORYSTATUSEX& memInfo) {
    // Get CPU usage
    // (Your CPU usage calculation code here)
    FILETIME idleTime, kernelTime, userTime;
    if (GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
        ULONGLONG kernelTimeDelta = kernelTime.dwLowDateTime + ((ULONGLONG)kernelTime.dwHighDateTime << 32);
        ULONGLONG userTimeDelta = userTime.dwLowDateTime + ((ULONGLONG)userTime.dwHighDateTime << 32);
        ULONGLONG idleTimeDelta = idleTime.dwLowDateTime + ((ULONGLONG)idleTime.dwHighDateTime << 32);

        static ULONGLONG prevIdleTime = 0, prevTotalTime = 0;
        ULONGLONG idleTimeDeltaDiff = idleTimeDelta - prevIdleTime;
        ULONGLONG totalTimeDelta = (kernelTimeDelta + userTimeDelta) - prevTotalTime;

        if (totalTimeDelta > 0) {
            cpuUsage = 100.0f * (1.0f - (static_cast<float>(idleTimeDeltaDiff) / totalTimeDelta));
        }

        prevIdleTime = idleTimeDelta;
        prevTotalTime = kernelTimeDelta + userTimeDelta;
    }


    // Get RAM usage
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    ramUsage = 100.0f * (1.0f - (static_cast<float>(memInfo.ullAvailPhys) / memInfo.ullTotalPhys));
}

std::string getUptime() {
    clock_t uptime = clock();
    int hours = uptime / CLOCKS_PER_SEC / 3600;
    int minutes = (uptime / CLOCKS_PER_SEC % 3600) / 60;
    int seconds = uptime / CLOCKS_PER_SEC % 60;

    char buffer[80];
    std::snprintf(buffer, sizeof(buffer), "Uptime: %02dh %02dm %02ds", hours, minutes, seconds);
    return buffer;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Performance Monitor");
    window.setFramerateLimit(NULL); // Limit frame rate

    sf::Image icon;
    if (icon.loadFromFile("icon.png")) {
        // Set the window icon
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    } else {
        // Handle the case where the icon couldn't be loaded
        // Optionally, you can use a default icon or display an error message.
    }


    sf::Font font;
    font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf");

    sf::Text uptimeText;
    uptimeText.setFont(font);
    uptimeText.setCharacterSize(20);
    uptimeText.setFillColor(sf::Color::White);
    uptimeText.setPosition(600, 10);

    sf::Text cpuText;
    cpuText.setFont(font);
    cpuText.setCharacterSize(20);
    cpuText.setFillColor(sf::Color::Green);
    cpuText.setPosition(windowWidth - chartWidth - chartMargin, windowHeight - chartMargin - 40); // Bottom right

    sf::Text ramText;
    ramText.setFont(font);
    ramText.setCharacterSize(20);
    ramText.setFillColor(sf::Color::Blue);
    ramText.setPosition(windowWidth - chartWidth - chartMargin, windowHeight - chartMargin - 10); // Bottom right

    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(20);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setPosition(600, 30); // Top left

    sf::RectangleShape cpuChart;
    cpuChart.setSize(sf::Vector2f(chartWidth / 2, 0));
    cpuChart.setFillColor(sf::Color::Green);
    cpuChart.setPosition(10, windowHeight - chartMargin);

    sf::RectangleShape ramChart;
    ramChart.setSize(sf::Vector2f(chartWidth / 2, 0));
    ramChart.setFillColor(sf::Color::Blue);
    ramChart.setPosition(10 + chartWidth / 2+10, windowHeight - chartMargin);

    MEMORYSTATUSEX memInfo;
    float cpuUsage = 0.0f;
    float ramUsage = 0.0f;
    int frameCount = 0;
    sf::Clock clock;
    sf::Clock fpsClock;
    int frames = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (clock.getElapsedTime().asMilliseconds() >= refreshInterval) {
            updateStats(cpuUsage, ramUsage, memInfo);

            std::string cpuUsageStr = "CPU: " + std::to_string(std::round(cpuUsage)) + "%";
            std::string ramUsageStr = "RAM: " + std::to_string(std::round(ramUsage)) + "%";

            cpuText.setString(cpuUsageStr);
            ramText.setString(ramUsageStr);

            uptimeText.setString(getUptime());

            std::cout << "\r" << cpuUsageStr << " | " << ramUsageStr << std::flush;

            float cpuHeight = chartHeight * (cpuUsage / 100.0f);
            float ramHeight = chartHeight * (ramUsage / 100.0f);

            cpuChart.setSize(sf::Vector2f(chartWidth / 2, -cpuHeight));
            ramChart.setSize(sf::Vector2f(chartWidth / 2, -ramHeight));

            frameCount++;
            if (frameCount * (refreshInterval / 1000.0f) >= chartWidth) {
                frameCount = chartWidth;
            }

            clock.restart();
        }

        frames++;
        if (fpsClock.getElapsedTime().asSeconds() >= 1.0) {
            int fps = frames;
            frames = 0;
            fpsText.setString("FPS: " + std::to_string(fps));
            fpsClock.restart();
        }

        window.clear(sf::Color::Black);
        window.draw(uptimeText);
        window.draw(cpuText);
        window.draw(ramText);
        window.draw(fpsText);
        window.draw(cpuChart);
        window.draw(ramChart);
        window.display();
    }

    return 0;
}
