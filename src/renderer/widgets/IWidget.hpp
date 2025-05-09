#pragma once

#include "../../helpers/Math.hpp"
#include "../../defines.hpp"
#include <string>
#include <unordered_map>
#include <any>

class COutput;

class IWidget {
  public:
    struct SRenderData {
        float opacity = 1;
    };

    virtual ~IWidget() = default;

    virtual void    configure(const std::unordered_map<std::string, std::any>& prop, const SP<COutput>& pOutput) = 0;
    virtual bool    draw(const SRenderData& data)                                                                = 0;

    static Vector2D posFromHVAlign(const Vector2D& viewport, const Vector2D& size, const Vector2D& offset, const std::string& halign, const std::string& valign,
                                   const double& ang = 0);
    static int      roundingForBox(const CBox& box, int roundingConfig);
    static int      roundingForBorderBox(const CBox& borderBox, int roundingConfig, int thickness);

    struct SFormatResult {
        std::string formatted;
        float       updateEveryMs    = 0; // 0 means don't (static)
        bool        alwaysUpdate     = false;
        bool        cmd              = false;
        bool        allowForceUpdate = false;
    };

    static SFormatResult formatString(std::string in);
};
