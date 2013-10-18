#ifndef VERTEXTYPES_HXX
#define VERTEXTYPES_HXX

#include <Global.hxx>

namespace Config {

namespace VertexTypes {
const EGraph::String Model { "Model" };
const EGraph::String FossilType { "Fossil Type" };
const EGraph::String Fossil { "Fossil" };
const EGraph::String TaxonType { "Taxon Type" };
const EGraph::String Taxon { "Taxon" };
const EGraph::String Facies { "Facies" };
const EGraph::String MapSymbolType { "Map Symbol Type" };
const EGraph::String MapSymbol { "Map Symbol" };
const EGraph::String SedimentologicFeature { "Sedimentologic Feature" };
const EGraph::String StratigraphicFeature { "Stratigraphic Feature" };
const EGraph::String TectonicFeature { "Tectonic Feature" };
const EGraph::String HydrologicFeature { "Hydrologic Feature" };
const EGraph::String TimeMarkType { "Time Mark Type" };
const EGraph::String TimeMark { "Time Mark" };
const EGraph::String AgeModelType { "Age Model Type" };
const EGraph::String AgeModel { "Age Model" };
const EGraph::String AgeModelInterval { "Age Model Interval" };
const EGraph::String MapLayerType { "Map Layer Type" };
const EGraph::String MapLayer { "Map Layer" };
const EGraph::String MapType { "Map Type" };
const EGraph::String Map { "Map" };
const EGraph::String CleavageType { "Cleavage Type" };
const EGraph::String LustreType { "Lustre Type" };
const EGraph::String Color { "Color" };
const EGraph::String CrystallographicPlane { "Crystallographic Plane" };
const EGraph::String StrunzClass { "Strunz Class" };
const EGraph::String Mineral { "Mineral" };
const EGraph::String FieldBook { "Field Book" };
const EGraph::String FieldBookEntry { "Field Book Entry" };
const EGraph::String InstrumentType { "Instrument Type" };
const EGraph::String Instrument { "Instrument" };
const EGraph::String InstrumentReading { "Instrument Reading" };
const EGraph::String MeasurementUnit { "Measurement Unit" };
}

namespace RoleTypes {
const EGraph::String IsPartOf { "Is Part Of" };
const EGraph::String Contains { "Contains" };
const EGraph::String IsSubType { "Is Sub Type" };
const EGraph::String IsSuperType { "Is Super Type" };
}

namespace PropertyNames {
const EGraph::String InstrumentReadingValue { "instrument_reading_value" };
}
}

#endif // VERTEXTYPES_HXX
