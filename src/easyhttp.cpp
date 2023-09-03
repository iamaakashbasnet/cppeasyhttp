#include <cpr/cpr.h>

class EasyHTTP
{
private:
    cpr::Response response_;

public:
    EasyHTTP() = default;

    EasyHTTP &get(const std::string &url, const cpr::Header &header = {})
    {
        response_ = cpr::Get(cpr::Url{url}, header);
        return *this;
    }

    EasyHTTP &post(const std::string &url,
                   const cpr::Header &header = {},
                   const cpr::Payload &payload = {})
    {
        response_ = cpr::Post(cpr::Url{url}, header, payload);
        return *this;
    }

    EasyHTTP &put(const std::string &url,
                  const cpr::Header &header = {},
                  const cpr::Payload &payload = {})
    {
        response_ = cpr::Put(cpr::Url{url}, header, payload);
        return *this;
    }

    EasyHTTP &del(const std::string &url, const cpr::Header &header = {})
    {
        response_ = cpr::Delete(cpr::Url{url}, header);
        return *this;
    }

    // Then callback handler
    EasyHTTP then(const std::function<void(const cpr::Response &)> &callback)
    {
        if (response_.error.code == cpr::ErrorCode::OK)
            callback(response_);

        return *this;
    }

    // Error callback handler
    EasyHTTP catchErr(const std::function<void(const cpr::Error &)> &onError)
    {
        if (response_.error.code != cpr::ErrorCode::OK)
            onError(response_.error);

        return *this;
    }
};