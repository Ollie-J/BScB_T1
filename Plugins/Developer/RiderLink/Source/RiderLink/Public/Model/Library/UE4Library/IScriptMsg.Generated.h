//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.07.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#ifndef ISCRIPTMSG_GENERATED_H
#define ISCRIPTMSG_GENERATED_H


#include "protocol/Protocol.h"
#include "types/DateTime.h"
#include "impl/RdSignal.h"
#include "impl/RdProperty.h"
#include "impl/RdList.h"
#include "impl/RdSet.h"
#include "impl/RdMap.h"
#include "base/ISerializersOwner.h"
#include "base/IUnknownInstance.h"
#include "serialization/ISerializable.h"
#include "serialization/Polymorphic.h"
#include "serialization/NullableSerializer.h"
#include "serialization/ArraySerializer.h"
#include "serialization/InternedSerializer.h"
#include "serialization/SerializationCtx.h"
#include "serialization/Serializers.h"
#include "ext/RdExtBase.h"
#include "task/RdCall.h"
#include "task/RdEndpoint.h"
#include "task/RdSymmetricCall.h"
#include "std/to_string.h"
#include "std/hash.h"
#include "std/allocator.h"
#include "util/enum.h"
#include "util/gen_util.h"

#include <cstring>
#include <cstdint>
#include <vector>
#include <ctime>

#include "thirdparty.hpp"
#include "../instantiations.h"

#include "UE4TypesMarshallers.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/Core/Public/Containers/ContainerAllocationPolicies.h"

#pragma warning( push )
#pragma warning( disable:4250 )
#pragma warning( disable:4307 )
#pragma warning( disable:4267 )
#pragma warning( disable:4244 )
#pragma warning( disable:4100 )

/// <summary>
/// <p>Generated from: UE4Library.kt:157</p>
/// </summary>
namespace JetBrains {
namespace EditorPlugin {

// abstract
class RIDERLINK_API IScriptMsg : public rd::IPolymorphicSerializable {

private:
    // custom serializers

public:
    // constants
    static constexpr rd::wstring_view header{L"Script msg:", 11};

protected:
    // fields

private:
    // initializer
    void initialize();

public:
    
    // default ctors and dtors
    
    IScriptMsg();
    
    IScriptMsg(IScriptMsg const &) = default;
    
    IScriptMsg& operator=(IScriptMsg const &) = default;
    
    IScriptMsg(IScriptMsg &&) = default;
    
    IScriptMsg& operator=(IScriptMsg &&) = default;
    
    virtual ~IScriptMsg() = default;
    
    // reader
    static rd::Wrapper<IScriptMsg> readUnknownInstance(rd::SerializationCtx& ctx, rd::Buffer & buffer, rd::RdId const& unknownId, int32_t size);
    
    // writer
    virtual void write(rd::SerializationCtx& ctx, rd::Buffer& buffer) const override = 0;
    
    // virtual init
    
    // identify
    
    // getters
    
    // intern

private:
    // equals trait

public:
    // equality operators
    friend bool operator==(const IScriptMsg &lhs, const IScriptMsg &rhs);
    friend bool operator!=(const IScriptMsg &lhs, const IScriptMsg &rhs);
    // hash code trait
    virtual size_t hashCode() const noexcept override = 0;
    // type name trait
    std::string type_name() const override;
    // static type name trait
    static std::string static_type_name();

private:
    // polymorphic to string
    std::string toString() const override;

public:
    // external to string
    friend std::string to_string(const IScriptMsg & value);
};

}
}

// hash code trait
namespace rd {

template <>
struct hash<JetBrains::EditorPlugin::IScriptMsg> {
    size_t operator()(const JetBrains::EditorPlugin::IScriptMsg & value) const noexcept {
        return value.hashCode();
    }
};

}

#pragma warning( pop )



#endif // ISCRIPTMSG_GENERATED_H
