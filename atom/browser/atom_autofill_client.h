// Copyright (c) 2016 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_ATOM_AUTOFILL_CLIENT_H_
#define ATOM_BROWSER_ATOM_AUTOFILL_CLIENT_H_

#include <memory>
#include <vector>

#include "base/callback.h"
#include "base/compiler_specific.h"
#include "base/i18n/rtl.h"
#include "base/macros.h"
#include "base/memory/weak_ptr.h"
#include "components/autofill/core/browser/autofill_client.h"
#include "components/autofill/core/browser/ui/card_unmask_prompt_controller_impl.h"
#include "components/ui/zoom/zoom_observer.h"
#include "content/public/browser/web_contents_observer.h"
#include "content/public/browser/web_contents_user_data.h"

namespace content {
struct FrameNavigateParams;
struct LoadCommittedDetails;
class WebContents;
}

namespace autofill {

class AutofillPopupControllerImpl;
class CreditCardScannerController;
struct FormData;

class AtomAutofillClient
    : public AutofillClient,
    public content::WebContentsUserData<AtomAutofillClient>,
    public content::WebContentsObserver,
    public ui_zoom::ZoomObserver {
public:
  ~AtomAutofillClient() override;
  // AutofillClient:
  PersonalDataManager* GetPersonalDataManager() override;
  scoped_refptr<AutofillWebDataService> GetDatabase() override;
  PrefService* GetPrefs() override;
  sync_driver::SyncService* GetSyncService() override;
  IdentityProvider* GetIdentityProvider() override;
  rappor::RapporService* GetRapporService() override;
  void ShowAutofillSettings() override;
  void ShowUnmaskPrompt(const CreditCard& card,
                        UnmaskCardReason reason,
                        base::WeakPtr<CardUnmaskDelegate> delegate) override;
  void OnUnmaskVerificationResult(PaymentsRpcResult result) override;
  void ConfirmSaveCreditCardLocally(const CreditCard& card,
                                    const base::Closure& callback) override;
  void ConfirmSaveCreditCardToCloud(
      const CreditCard& card,
      std::unique_ptr<base::DictionaryValue> legal_message,
      const base::Closure& callback) override;
  void LoadRiskData(
      const base::Callback<void(const std::string&)>& callback) override;
  bool HasCreditCardScanFeature() override;
  void ScanCreditCard(const CreditCardScanCallback& callback) override;
  void ShowAutofillPopup(
      const gfx::RectF& element_bounds,
      base::i18n::TextDirection text_direction,
      const std::vector<autofill::Suggestion>& suggestions,
      base::WeakPtr<AutofillPopupDelegate> delegate) override;
  void UpdateAutofillPopupDataListValues(
      const std::vector<base::string16>& values,
      const std::vector<base::string16>& labels) override;
  void HideAutofillPopup() override;
  bool IsAutocompleteEnabled() override;
  void PropagateAutofillPredictions(
      content::RenderFrameHost* rfh,
      const std::vector<autofill::FormStructure*>& forms) override;
  void DidFillOrPreviewField(const base::string16& autofilled_value,
                             const base::string16& profile_full_name) override;
  void OnFirstUserGestureObserved() override;
  bool IsContextSecure(const GURL& form_origin) override;

  // content::WebContentsObserver implementation.
  void MainFrameWasResized(bool width_changed) override;
  void WebContentsDestroyed() override;

  // ZoomObserver implementation.
  void OnZoomChanged(
      const ui_zoom::ZoomController::ZoomChangedEventData& data) override;

 private:
  explicit AtomAutofillClient(content::WebContents* web_contents);
  friend class content::WebContentsUserData<AtomAutofillClient>;

  base::WeakPtr<AutofillPopupControllerImpl> popup_controller_;
  CardUnmaskPromptControllerImpl unmask_controller_;

  // The identity provider, used for Payments integration.
  std::unique_ptr<IdentityProvider> identity_provider_;

  DISALLOW_COPY_AND_ASSIGN(AtomAutofillClient);
};

}  // namespace autofill

#endif  // ATOM_BROWSER_ATOM_AUTOFILL_CLIENT_H_
