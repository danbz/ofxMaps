//
// Copyright (c) 2014 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "Poco/RegularExpression.h"


namespace ofx {
namespace Maps {


class TileTemplate
{
public:
    /// \brief A utility method for extracting parameters from a template.
    /// \param URITemplate The URI template to extract.
    static std::vector<std::string> extractTemplateParameters(const std::string& URITemplate);

    /// \brief Converts tile coordinates into a QuadKey at a specified level of detail.
    /// \param tileX Tile X coordinate.
    /// \param tileY Tile Y coordinate.
    /// \param levelOfDetail Level of detail, from 1 (lowest detail) to 23 (highest detail).
    /// \returns a string containing the QuadKey.
    /// \sa https://msdn.microsoft.com/en-us/library/bb259689.aspx
    static std::string tileCoordinateToQuadKey(int tileX,
                                               int tileY,
                                               int levelOfDetail);

    /// \brief Converts a QuadKey into tile XY coordinates.
    /// \param quadKey QuadKey of the tile.
    /// \param tileX Output parameter receiving the tile X coordinate.</param>
    /// \param tileY Output parameter receiving the tile Y coordinate.</param>
    /// \param levelOfDetail Output parameter receiving the level of detail
    /// \returns true if a valid quad key was used.
    /// \sa https://msdn.microsoft.com/en-us/library/bb259689.aspx
    static bool quadKeyToTileCoordinate(const std::string& quadKey,
                                        int& tileX,
                                        int& tileY,
                                        int& levelOfDetail);

    /// \brief A regular expression used for extracting the template parameters.
    ///
    /// This template specifically searches for single mustache-style
    /// (e.g. {PARAMETER}) template parameters in the URI templates.
    static const Poco::RegularExpression TEMPLATE_PARAM_REGEX;

    static const std::string TEMPLATE_PARAM_QUADKEY;
    static const std::string TEMPLATE_PARAM_ZOOM;
    static const std::string TEMPLATE_PARAM_X;
    static const std::string TEMPLATE_PARAM_Y;
    static const std::string TEMPLATE_PARAM_TILE_ID;
    static const std::string TEMPLATE_PARAM_SET_ID;

};



} } // namespace ofx::Maps
