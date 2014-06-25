// =============================================================================
//
// Copyright (c) 2014 Christopher Baker <http://christopherbaker.net>
// Copyright (c) -2014 Tom Carden <https://github.com/RandomEtc>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#include "ofx/Maps/BaseMapTileProvider.h"


namespace ofx {
namespace Maps {


BaseMapTileProvider::BaseMapTileProvider(int minZoom,
                                         int maxZoom,
                                         int tileWidth,
                                         int tileHeight,
                                         const BaseProjection& projection):
    _minZoom(minZoom),
    _maxZoom(maxZoom),
    _tileWidth(tileWidth),
    _tileHeight(tileHeight),
    _projection(projection)
{
}


BaseMapTileProvider::~BaseMapTileProvider()
{
}


int BaseMapTileProvider::getMinZoom() const
{
    return _minZoom;
}


int BaseMapTileProvider::getMaxZoom() const
{
    return _maxZoom;
}


int BaseMapTileProvider::getTileWidth() const
{
    return _tileWidth;
}


int BaseMapTileProvider::getTileHeight() const
{
    return _tileHeight;
}


ofVec2d BaseMapTileProvider::getTileSize() const
{
    return ofVec2d(_tileWidth, _tileHeight);
}

    
double BaseMapTileProvider::zoomForScale(double scale) const
{
    return log(scale) / log(2);
}


TileCoordinate BaseMapTileProvider::geoToTile(const Geo::Coordinate& location) const
{
    
    return _projection.geoToTile(location);
}


Geo::Coordinate BaseMapTileProvider::tileToGeo(const TileCoordinate& coordinate) const
{
    return _projection.tileToGeo(coordinate);
}


} } // namespace ofx::Maps