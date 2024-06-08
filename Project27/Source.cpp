#include <iostream>
#include <string>
using namespace std;

class Device 
{
public:
    virtual ~Device() = default;
    virtual string GetInfo() const = 0;
};

class VideoCard : public Device 
{
public:
    string GetInfo() const override 
    {
        return "Video Card: NVIDIA GeForce RTX 3080";
    }
};

class Processor : public Device 
{
public:
    string GetInfo() const override 
    {
        return "Processor: Intel Core i9-11900K";
    }
};

class HardDrive : public Device {
public:
    string GetInfo() const override 
    {
        return "Hard Drive: Samsung 970 EVO 1TB";
    }
};

class RAM : public Device 
{
public:
    string GetInfo() const override 
    {
        return "RAM: Corsair Vengeance LPX 16GB";
    }
};

class Report 
{
protected:
    Device* device_;
public:
    Report(Device* device) : device_(device) {}
    virtual ~Report() = default;
    virtual void Show() const = 0;
};

class DetailedReport : public Report 
{
public:
    DetailedReport(Device* device) : Report(device) {}

    void Show() const override 
    {
        cout << "Detailed Report: " << device_->GetInfo() << endl;
    }
};

class SummaryReport : public Report 
{
public:
    SummaryReport(Device* device) : Report(device) {}

    void Show() const override 
    {
        cout << "Summary Report: " << device_->GetInfo() << endl;
    }
};

int main() 
{
    VideoCard videoCard;
    Processor processor;
    HardDrive hardDrive;
    RAM ram;

    DetailedReport detailedReportVideoCard(&videoCard);
    SummaryReport summaryReportProcessor(&processor);
    DetailedReport detailedReportHardDrive(&hardDrive);
    SummaryReport summaryReportRAM(&ram);

    detailedReportVideoCard.Show();
    summaryReportProcessor.Show();
    detailedReportHardDrive.Show();
    summaryReportRAM.Show();

    return 0;
}
