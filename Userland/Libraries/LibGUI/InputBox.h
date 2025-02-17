/*
 * Copyright (c) 2018-2020, Andreas Kling <kling@serenityos.org>
 * Copyright (c) 2021, networkException <networkexception@serenityos.org>
 * Copyright (c) 2022, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGUI/Dialog.h>

namespace GUI {

enum class InputType {
    Text,
    Password
};

class InputBox : public Dialog {
    C_OBJECT(InputBox)
public:
    virtual ~InputBox() override = default;

    static ExecResult show(Window* parent_window, String& text_value, StringView prompt, StringView title, StringView placeholder = {}, InputType input_type = InputType::Text);

    String const& text_value() const { return m_text_value; }
    void set_text_value(String text_value);

private:
    explicit InputBox(Window* parent_window, String text_value, StringView prompt, StringView title, StringView placeholder, InputType input_type);

    virtual void on_done(ExecResult) override;
    void build(InputType input_type);

    String m_text_value;
    String m_prompt;
    String m_placeholder;

    RefPtr<Button> m_ok_button;
    RefPtr<Button> m_cancel_button;
    RefPtr<TextEditor> m_text_editor;
};

}
