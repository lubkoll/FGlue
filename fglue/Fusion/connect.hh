#ifndef FGLUE_FUSION_CONNECT_HH
#define FGLUE_FUSION_CONNECT_HH

namespace FGlue
{

  template <class SourceOperation, class TargetOperation = SourceOperation>
  struct Connector
  {
    template <class Source, bool valid = isTrue< Apply<SourceOperation,Source> >() >
    struct From
    {
      From(Source& source)
        : source_(source)
      {}

      template <class... Targets>
      static void to(Targets&... targets)
      {
        attach(source,targets...);
      }

      Source& source_;
    };

    template <class Source>
    struct From<Source,false>
    {
      From(Source&){}

      template <class... Targets>
      static void to(Targets&...)
      {}
    };

    template <class Source>
    static auto from(Source& source)
    {
      return From<Source>(source);
    }
  };
}

#endif // FGLUE_FUSION_CONNECT_HH
