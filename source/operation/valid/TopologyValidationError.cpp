/**********************************************************************
 * $Id$
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.refractions.net
 *
 * Copyright (C) 2005-2006 Refractions Research Inc.
 * Copyright (C) 2001-2002 Vivid Solutions Inc.
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 **********************************************************************
 *
 * Last port: operation/valid/TopologyValidationError.java rev. 1.14 (JTS-1.7)
 *
 **********************************************************************/

#include <geos/operation/valid/TopologyValidationError.h>
#include <geos/geom/Coordinate.h>

#include <string>

using namespace std;
using namespace geos::geom;

namespace geos {
namespace operation { // geos.operation
namespace valid { // geos.operation.valid

const char* TopologyValidationError::errMsg[]={
	"Topology Validation Error",
	"Repeated Point",
	"Hole lies outside shell",
	"Holes are nested",
	"Interior is disconnected",
	"Self-intersection",
	"Ring Self-intersection",
	"Nested shells",
	"Duplicate Rings",
	"Too few points in geometry component",
	"Invalid Coordinate",
	"Ring is not closed"
};

TopologyValidationError::TopologyValidationError(int newErrorType,
		const Coordinate& newPt)
	:
	errorType(newErrorType),
	pt(newPt)
{
}

TopologyValidationError::TopologyValidationError(int newErrorType)
	:
	errorType(newErrorType),
	pt(Coordinate::getNull())
{
}

int
TopologyValidationError::getErrorType()
{
	return errorType;
}

Coordinate&
TopologyValidationError::getCoordinate()
{
	return pt;
}

string
TopologyValidationError::getMessage()
{
	return string(errMsg[errorType]);
}

string
TopologyValidationError::toString()
{
	return (getMessage().append(" at or near point")).append(pt.toString());
}

} // namespace geos.operation.valid
} // namespace geos.operation
} // namespace geos

/**********************************************************************
 * $Log$
 * Revision 1.15  2006/03/20 16:57:44  strk
 * spatialindex.h and opValid.h headers split
 *
 * Revision 1.14  2006/03/03 10:46:22  strk
 * Removed 'using namespace' from headers, added missing headers in .cpp files, removed useless includes in headers (bug#46)
 *
 * Revision 1.13  2006/03/01 10:48:55  strk
 * Changed static TopologyValidationError::errMsg[] from 'string' to 'const char*'
 * to reduce dynamic memory allocations.
 *
 * Revision 1.12  2006/02/23 23:17:52  strk
 * - Coordinate::nullCoordinate made private
 * - Simplified Coordinate inline definitions
 * - LMGeometryComponentFilter definition moved to LineMerger.cpp file
 * - Misc cleanups
 *
 * Revision 1.11  2006/02/19 19:46:50  strk
 * Packages <-> namespaces mapping for most GEOS internal code (uncomplete, but working). Dir-level libs for index/ subdirs.
 *
 * Revision 1.10  2006/01/20 19:11:09  strk
 * Updated last port info
 *
 * Revision 1.9  2005/11/04 11:04:09  strk
 * Ported revision 1.38 of IsValidOp.java (adding closed Ring checks).
 * Changed NestedRingTester classes to use Coorinate pointers
 * rather then actual objects, to speedup NULL tests.
 * Added JTS port revision when applicable.
 *
 * Revision 1.8  2004/11/05 11:41:57  strk
 * Made IsValidOp handle IllegalArgumentException throw from GeometryGraph
 * as a sign of invalidity (just for Polygon geometries).
 * Removed leaks generated by this specific exception.
 *
 * Revision 1.7  2004/09/13 10:14:47  strk
 * Added INVALID_COORDINATE code num and error message.
 *
 * Revision 1.6  2004/07/02 13:28:29  strk
 * Fixed all #include lines to reflect headers layout change.
 * Added client application build tips in README.
 *
 * Revision 1.5  2003/11/07 01:23:43  pramsey
 * Add standard CVS headers licence notices and copyrights to all cpp and h
 * files.
 *
 *
 **********************************************************************/

