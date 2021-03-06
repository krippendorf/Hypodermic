#ifndef		HYPODERMIC_TYPED_SERVICE_H_
# define	HYPODERMIC_TYPED_SERVICE_H_

# include <boost/noncopyable.hpp>
# include <Hypodermic/Service.h>
# include <Hypodermic/TypeIndexWorkaround.h>

namespace Hypodermic
{

    class TypedService : public Service,
        private boost::noncopyable
    {
    public:
        TypedService(const std::type_info& typeInfo);

        const std::type_info& typeInfo() const;

        bool operator==(const Service& rhs) const;
        std::size_t hashValue() const;

    private:
        const std::type_info& typeInfo_;
        const std::type_index typeIndex_;
    };

} // namespace Hypodermic


#endif /* !HYPODERMIC_TYPED_SERVICE_H_ */