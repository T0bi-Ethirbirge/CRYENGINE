// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include "BaseConnection.h"

#include <PoolObject.h>
#include <CryAudioImplWwise/GlobalData.h>

namespace ACE
{
namespace Impl
{
namespace Wwise
{
class CParameterConnection final : public CBaseConnection, public CryAudio::CPoolObject<CParameterConnection, stl::PSyncNone>
{
public:

	CParameterConnection() = delete;
	CParameterConnection(CParameterConnection const&) = delete;
	CParameterConnection(CParameterConnection&&) = delete;
	CParameterConnection& operator=(CParameterConnection const&) = delete;
	CParameterConnection& operator=(CParameterConnection&&) = delete;

	explicit CParameterConnection(
		ControlId const id,
		float const mult = CryAudio::Impl::Wwise::s_defaultParamMultiplier,
		float const shift = CryAudio::Impl::Wwise::s_defaultParamShift)
		: CBaseConnection(id)
		, m_mult(mult)
		, m_shift(shift)
	{}

	virtual ~CParameterConnection() override = default;

	// CBaseConnection
	virtual bool HasProperties() const override { return true; }
	virtual void Serialize(Serialization::IArchive& ar) override;
	// ~CBaseConnection

	float GetMultiplier() const { return m_mult; }
	float GetShift() const      { return m_shift; }

private:

	float m_mult;
	float m_shift;
};
} // namespace Wwise
} // namespace Impl
} // namespace ACE
