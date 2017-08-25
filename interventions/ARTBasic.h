/***************************************************************************************************

Copyright (c) 2017 Intellectual Ventures Property Holdings, LLC (IVPH) All rights reserved.

EMOD is licensed under the Creative Commons Attribution-Noncommercial-ShareAlike 4.0 License.
To view a copy of this license, visit https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode

***************************************************************************************************/

#pragma once

#include "Drugs.h"

namespace Kernel
{
    struct IHIVDrugEffectsApply;

    class ARTBasic : public GenericDrug
    {
        DECLARE_FACTORY_REGISTERED(InterventionFactory, ARTBasic, IDistributableIntervention);

    public:
        bool Configure( const Configuration * );
        ARTBasic();
        virtual ~ARTBasic();

        // ISupports
        virtual QueryResult QueryInterface(iid_t iid, void **ppvObject) override;
        virtual void SetContextTo(IIndividualHumanContext *context) override;

        // IDistributableIntervention
        virtual bool Distribute(IIndividualHumanInterventionsContext *context, ICampaignCostObserver * const pCCO ) override;

        virtual std::string GetDrugName() const override;

    protected:
        // These have same names as analogous methods on container but are internal for the drug itself.

        bool viral_suppression;
        float days_to_achieve_suppression ;

        virtual void ApplyEffects() override;

        IHIVDrugEffectsApply * itbda;

        DECLARE_SERIALIZABLE(ARTBasic);
    };
}